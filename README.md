# 2out

Object oriented unit testing framework

![EO badge](https://www.elegantobjects.org/badge.svg)

![Actions](https://github.com/DronMDF/2out/workflows/Build/badge.svg)
[![codecov](https://codecov.io/gh/DronMDF/2out/branch/master/graph/badge.svg)](https://codecov.io/gh/DronMDF/2out)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/DronMDF/2out/blob/master/LICENSE)

# Intro

The test framework should not be easy to use.
The test framework should help to do everything right.
And after that it should be easy to use. :)

# Tutorial

## Kent Beck Money example

1. Money as a Text. [ru](tutorial/TUTORIAL1.ru.md)
2. Money multiplication. [ru](tutorial/TUTORIAL2.ru.md)
3. Business terminoligy. [ru](tutorial/TUTORIAL3.ru.md)
4. Total Order amount. [ru](tutorial/TUTORIAL4.ru.md)
5. OrderMoney corner cases. [ru](tutorial/TUTORIAL5.ru.md)
6. Currency Exchange. [ru](tutorial/TUTORIAL6.ru.md)
7. Suite of tests. [ru](tutorial/TUTORIAL7.ru.md)

# Using

## With cmake

conanfile.txt:
```
[generators]
cmake

[requires]
2out/0.9@dronmdf/stable
```

CMakeLists.txt:
```
INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
```

build:
```sh
$ conan remote add pureoop-2out https://conan.cloudsmith.io/pureoop/2out
$ conan install ~/project --build
$ cmake ~/project
$ make
```

# Related projects

* https://github.com/g4s8/oot Experimental Object Oriented Testing Framework for Java
* https://github.com/pragmatic-objects/oo-tests Reusable test assertions for JUnit5

# Contributing

Any contribution are welcome.
Follow this [guide](CONTRIBUTING.md).
