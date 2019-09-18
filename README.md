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
[Part 1](example/TUTORIAL1.ru.md) [ru]

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
