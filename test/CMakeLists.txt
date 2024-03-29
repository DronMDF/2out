CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

PROJECT(test)

INCLUDE_DIRECTORIES(${2out_SOURCE_DIR}/..)

ADD_EXECUTABLE(
	test_runner
	test.cpp
	CondResultTest.cpp
	ContainMatchTest.cpp
	ContainTestTest.cpp
	CountErrorTest.cpp
	CountFailureRepr.cpp
	CountFailureTest.cpp
	CountTestTest.cpp
	CtorExceptionTextTest.cpp
	DirtyTestTest.cpp
	EndsWithMatchTest.cpp
	EndsWithTestTest.cpp
	FunctionTextTest.cpp
	MethodExceptionTextTest.cpp
	MatchTestTest.cpp
	NamedTestTest.cpp
	OoutReportTextTest.cpp
	PrintableTextTest.cpp
	RegexMatchTest.cpp
	RegexTestTest.cpp
	SafeTestTest.cpp
	SkippedTestTest.cpp
	StartsWithMatchTest.cpp
	StartsWithTestTest.cpp
	SuiteTestTest.cpp
	TestText.cpp
	GtestReportTextTest.cpp
	XmlReportTextTest.cpp
)
TARGET_LINK_LIBRARIES(
	test_runner
	2out
)

ADD_TEST(
	NAME test
	COMMAND test_runner
)
