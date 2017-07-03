CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(test)

INCLUDE_DIRECTORIES(${2out_SOURCE_DIR}/..)

ADD_EXECUTABLE(
	test_runner
	test.cpp
	CountErrorTest.cpp
	CountFailureTest.cpp
	CountTestTest.cpp
	JUnitXmlReportTest.cpp
	ReprPrintableTest.cpp
	ResFakes.cpp
	TestSuiteTest.cpp
	TextReportTest.cpp
)
TARGET_LINK_LIBRARIES(
	test_runner
	2out
)

ADD_CUSTOM_COMMAND(
	TARGET test_runner
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/shippable/testresults
)

# @todo #54:15min shippable path - this is shippable lock in sources
#  test_runner can write report to file, file placement define in shippable.yml (copy)
ADD_TEST(
	NAME test
	COMMAND sh -c "./test_runner > ${CMAKE_BINARY_DIR}/shippable/testresults/result.xml"
)
