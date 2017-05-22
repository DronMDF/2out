#!/bin/sh

set -ue

cppcheck -I. -Itest --enable=all --suppress=missingIncludeSystem --quiet .
./cpplint.py `find ./ -name *.cpp -o -name *.h`

# Scan sources for wrong pdd tokens
pdd > /dev/null
