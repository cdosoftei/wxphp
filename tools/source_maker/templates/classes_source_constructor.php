<?=proto_begin($method_name, $class_name)?>
PHP_METHOD(php_<?=$class_name?>, __construct)
{
    #ifdef USE_WXPHP_DEBUG
    php_printf("Invoking <?=$class_name?>::__construct\n");
    php_printf("===========================================\n");
    #endif

    zo_<?=$class_name?>* current_object;
    <?=$class_name?>_php* native_object;
    void* argument_native_object = NULL;

    //Other variables used thru the code
    zval dummy;
    ZVAL_NULL(&dummy);
    bool already_called = false;
    int arguments_received = ZEND_NUM_ARGS();


    <?=function_parameters($method_definitions, $method_name, $class_name)?>

    <?=function_called_overload($method_definitions, $method_name, $class_name)?>

    <?=function_return($method_definitions, $method_name, $class_name, true)?>

    if(already_called)
    {
        native_object->phpObj = *getThis();

<?if(class_has_properties($class_name)){?>
        native_object->InitProperties();
<?}?>

        current_object = Z_<?=$class_name?>_P(getThis());

        current_object->native_object = native_object;
        native_object->zo = current_object;

        current_object->is_user_initialized = 1;
    }
    else
    {
        zend_error(
            E_ERROR,
            "Abstract class or wrong type/count of parameters "
            "passed to: <?=$class_name?>::__construct\n"
        );
    }

    #ifdef USE_WXPHP_DEBUG
        php_printf("===========================================\n\n");
    #endif
}
<?=proto_end()?>
