#!/usr/bin/env php
<?php

$patch = false;

$selected = json_decode(file_get_contents('./tools/source_maker/class_selector/classes.json'));
$all = json_decode(file_get_contents('./json/classes.json'));

if ($patch) {
  copy('./tools/source_maker/class_selector/classes.json', './tools/source_maker/class_selector/classes.' . time() . '.json');
}

foreach ($selected as $class => $props) {
  if (!isset($all->{$class})) {
    echo "Class {$class} has been removed\n";
    continue;
  }

  foreach ($props as $prop => $val) {
    if (!isset($all->{$class}->{$prop})) {
      echo "Property {$class}::{$prop} has been removed\n";
      continue;
    }

    $changed = propDiff("{$class}::{$prop}", $val, $all->{$class}->{$prop});

    if ($changed && $patch) {
      $selected->{$class}->{$prop} = $all->{$class}->{$prop};
    }
  }
}

if ($patch) {
  file_put_contents('./tools/source_maker/class_selector/classes.json', json_encode($selected, JSON_PRETTY_PRINT));
}

function propDiff($label, $orig, $new): bool {
  $otype = gettype($orig);
  $ntype = gettype($new);

  if (str_ends_with($label, 'brief_description')) {
    return false;
  }

  if ($otype != $ntype) {
    echo "{$label} changed its type from `{$otype}` to `{$ntype}`\n";
    return true;
  }

  if (is_scalar($orig)) {
    if ($orig != $new) {
      echo "{$label} changed from `{$orig}` to `{$new}`\n";
      return true;
    } else {
      return false;
    }
  }

  if (is_null($orig) && is_null($new)) {
    return false;
  }

  if (is_array($orig) || is_object($orig)) {
    if ($orig != $new) {
      foreach ($orig as $k => $v) {
        if (is_array($orig)) {
          if (isset($new[$k])) {
            propDiff("{$label}[{$k}]", $v, $new[$k]);
          } else {
            echo "{$label}[{$k}] has been removed\n";
          }
        } else {
          propDiff("{$label}::{$k}", $v, $new->{$k});
        }
      }
    } else {
      return false;
    }
  } else {
    die("Don't know how to diff `$otype` type:\n" . json_encode($orig) . "\n" . json_encode($new));
  }

  return false;
}
