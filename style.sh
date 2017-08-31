#!/bin/sh

set -ue

# Check coding style
cppcheck -I. -Itest --enable=all --suppress=missingIncludeSystem --quiet 2out test
./cpplint.py `find 2out/ -name *.cpp -o -name *.h` `find test/ -name *.cpp -o -name *.h`
uncrustify -c uncrustify.conf --check -q `find 2out/ -name *.cpp -o -name *.h` `find test/ -name *.cpp -o -name *.h`

# Check pdd tokens
pdd > /dev/null

# Check inline documentation
rm -rf html
if doxygen 2>&1 | grep "is not documented"; then
	exit 1
fi
