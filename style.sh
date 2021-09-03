#!/bin/sh

set -ue

# Check coding style
cppcheck -I. -Itest --enable=all --suppress=missingIncludeSystem --quiet 2out test tutorial
cpplint `find 2out/ -name *.cpp -o -name *.h`
cpplint `find test/ -name *.cpp -o -name *.h`
cpplint `find tutorial/ -name *.cpp -o -name *.h`
# @todo #256 uncrustify in ubuntu Trusty is very old (0.59)
#  this version not understood c++11 features and trash my code.
#  wait for 0.64
#uncrustify -c uncrustify.conf --check -q `find 2out/ -name *.cpp -o -name *.h` `find test/ -name *.cpp -o -name *.h`

# Check inline documentation
#rm -rf html
#if doxygen 2>&1 | grep "is not documented"; then
#	exit 1
#fi

echo Success
