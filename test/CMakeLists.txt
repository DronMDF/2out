CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(test)

INCLUDE_DIRECTORIES(${2out_SOURCE_DIR}/..)

ADD_EXECUTABLE(
	test_runner
	test.cpp
	ContainMatchTest.cpp
	ContainTestTest.cpp
	CondResultTest.cpp
	CountErrorTest.cpp
	CountFailureRepr.cpp
	CountFailureTest.cpp
	CountTestTest.cpp
	DirtyTestTest.cpp
	EndsWithMatchTest.cpp
	EndsWithTestTest.cpp
	JUnitXmlReportTest.cpp
	MatchTestTest.cpp
	NamedTestTest.cpp
	ReprCallableTest.cpp
	ReprPrintableTest.cpp
	ReprTest.cpp
	ResFakes.cpp
	SkippedTestTest.cpp
	StartsWithMatchTest.cpp
	StartsWithTestTest.cpp
	SuiteTestTest.cpp
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
