CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(tutorial)

INCLUDE_DIRECTORIES(${2out_SOURCE_DIR}/..)

ADD_EXECUTABLE(
	tutorial
	tutorial.cpp
	Bank.cpp
	ExchangedMoney.cpp
	MoneyText.cpp
	OrderItemMoney.cpp
	OrderMoney.cpp
	OrderMoneyTest.cpp
	RealMoney.cpp
)

TARGET_LINK_LIBRARIES(
	tutorial
	2out
)

ADD_TEST(
	NAME tutorial
	COMMAND tutorial
)
