CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(test)

ADD_EXECUTABLE(
	test_runner
	test.cpp
)
TARGET_LINK_LIBRARIES(
	test_runner
	2out
)

ADD_TEST(NAME test COMMAND test_runner)
