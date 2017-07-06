#!/bin/sh

set -ue

cppcheck -I. -Itest --enable=all --suppress=missingIncludeSystem --quiet 2out test
./cpplint.py `find 2out/ -name *.cpp -o -name *.h` `find test/ -name *.cpp -o -name *.h`

# Scan sources for wrong pdd tokens
pdd > /dev/null
