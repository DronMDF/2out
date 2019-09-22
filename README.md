# 2out

Object oriented unit testing framework

![EO badge](https://www.elegantobjects.org/badge.svg)

[![CircleCI](https://circleci.com/gh/DronMDF/2out.svg?style=shield)](https://circleci.com/gh/DronMDF/2out)
[![codecov](https://codecov.io/gh/DronMDF/2out/branch/master/graph/badge.svg)](https://codecov.io/gh/DronMDF/2out)
[![PDD status](http://www.0pdd.com/svg?name=DronMDF/2out)](http://www.0pdd.com/p?name=DronMDF/2out)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/DronMDF/2out/blob/master/LICENSE)

# Intro

The test framework should not be easy to use.
The test framework should help to do everything right.
And after that it should be easy to use. :)

# Tutorial

## Kent Beck Money example

1. Money as a Text. [ru](example/TUTORIAL1.ru.md)
2. Money multiplication. [ru](example/TUTORIAL2.ru.md)
3. Business terminoligy. [ru](example/TUTORIAL3.ru.md)
4. Total Order amount. [ru](example/TUTORIAL4.ru.md)
5. OrderMoney corner cases. [ru](example/TUTORIAL5.ru.md)
6. Currency Exchange.
7. Suite of tests.

# Using

## With cmake

conanfile.txt:
```
[generators]
cmake

[requires]
2out/0.6@dronmdf/stable
```

CMakeLists.txt:
```
INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
```

build:
```sh
$ conan remote add mdf https://api.bintray.com/conan/mdf/2out
$ conan install ~/project --build
$ cmake ~/project
$ make
```

# Contributing

Any contribution are welcome.
Follow this [guide](CONTRIBUTING.md).
