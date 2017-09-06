PROJECT(test_package)

INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

ADD_DEFINITIONS("-std=c++14 -Wall -Wextra -Weffc++ -Werror")

ADD_EXECUTABLE(
	example
	example.cpp
)

TARGET_LINK_LIBRARIES(
	example
	${CONAN_LIBS}
)

enable_testing()
add_test(
	NAME example
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
	COMMAND example
)
