#!/bin/sh

rm -f Makefile* && cd ./tools/source_maker && ./go.sh && cd ../.. && phpize && ./configure && make -j8
