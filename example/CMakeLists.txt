CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(example)

INCLUDE_DIRECTORIES(${2out_SOURCE_DIR}/..)

ADD_EXECUTABLE(
	example
	example.cpp
	MoneyText.cpp
	RealMoney.cpp
	TimesMoney.cpp
)

TARGET_LINK_LIBRARIES(
	example
	2out
)

ADD_TEST(
	NAME example
	COMMAND example
)
