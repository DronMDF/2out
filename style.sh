#!/bin/sh

set -ue

cppcheck -I. -Itest --enable=all --suppress=missingIncludeSystem --quiet 2out test
./cpplint.py `find 2out/ -name *.cpp -o -name *.h` `find test/ -name *.cpp -o -name *.h`

# Scan sources for wrong pdd tokens
pdd > /dev/null

# @todo #257 Add doxygen documentation to all classes (cleanup doxygen errors)

# Check doccumentation (all undocummented threat as error)
doxygen 2>&1 | grep "is not documented" && false
