CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(test)

INCLUDE_DIRECTORIES(${2out_SOURCE_DIR}/..)

ADD_EXECUTABLE(
	test_runner
	test.cpp
	CountErrorTest.cpp
	CountFailureTest.cpp
	CountTestTest.cpp
	DirtyTestTest.cpp
	JUnitXmlReportTest.cpp
	ReprCallableTest.cpp
	ReprPrintableTest.cpp
	ReprTest.cpp
	ResFakes.cpp
	SuiteTestTest.cpp
	TestContainTextTest.cpp
	TestEndsWithTest.cpp
	TestNamedTest.cpp
	TestSkippedTest.cpp
	StartsWithTestTest.cpp
	TextReportTest.cpp
)
TARGET_LINK_LIBRARIES(
	test_runner
	2out
)

ADD_TEST(
	NAME test
	COMMAND sh -c "./test_runner > ${CMAKE_BINARY_DIR}/test-results.xml"
)
