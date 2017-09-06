PROJECT(test_package)

INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
CONAN_BASIC_SETUP()

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
