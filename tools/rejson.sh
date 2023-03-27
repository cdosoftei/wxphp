#!/bin/sh

cd wxWidgets-3.2.0/docs/doxygen
WX_SKIP_DOXYGEN_VERSION_CHECK=1 ./regen.sh xml
mv out/xml/* ../../../xml
cd ../../..
php ./tools/json_generator.php
