CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# @todo #169:15min Add custom target 'style' for stylecheck

ENABLE_TESTING()

ADD_DEFINITIONS("-std=c++14 -Wall -Wextra -Weffc++ -Werror")

ADD_SUBDIRECTORY(2out)
ADD_SUBDIRECTORY(test)
