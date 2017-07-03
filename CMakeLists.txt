CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# @todo #169:15min Add custom target 'style' for stylecheck

ENABLE_TESTING()

ADD_DEFINITIONS("-std=c++14 -Wall -Wextra -Weffc++ -Werror")

# @todo #223:15min Remove include directories from root.
#  test reference youself to root directory as include directory.
#  2out not need to specify include directory.
INCLUDE_DIRECTORIES(.)
INCLUDE_DIRECTORIES(2out)

ADD_SUBDIRECTORY(2out)
ADD_SUBDIRECTORY(test)
