CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(example)

INCLUDE_DIRECTORIES(${2out_SOURCE_DIR}/..)

ADD_EXECUTABLE(
	example
	example.cpp
	Money.cpp
	MoneyText.cpp
)

TARGET_LINK_LIBRARIES(
	example
	2out
)

ADD_TEST(
	NAME example
	COMMAND sh -c "./example > ${CMAKE_BINARY_DIR}/example-results.xml"
)
