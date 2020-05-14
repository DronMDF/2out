CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(2out)

ADD_LIBRARY(
	2out

	# Tests
	ContainTest.cpp
	CountTest.cpp
	EndsWithTest.cpp
	EqualTest.cpp
	MatchTest.cpp
	NamedTest.cpp
	RegexTest.cpp
	SafeTest.cpp
	SkippedTest.cpp
	StartsWithTest.cpp
	SuiteTest.cpp
	TimedTest.cpp
	dirty/Test.cpp

	# Matches
	AllMatch.cpp
	ContainMatch.cpp
	EndsWithMatch.cpp
	EqualMatch.cpp
	RegexMatch.cpp
	StartsWithMatch.cpp

	# Result
	CondResult.cpp
	ErrorResult.cpp
	FailureResult.cpp
	NamedResult.cpp
	SuccessResult.cpp
	SuiteResult.cpp
	TestResult.cpp
	TimedResult.cpp

	# Text
	FunctionText.cpp
	GtestReportText.cpp
	MethodExceptionText.cpp
	OoutReportText.cpp
	SignedText.cpp
	StringText.cpp
	XmlReportText.cpp

	# Misc
	CountError.cpp
	CountFailure.cpp
	OoutFormat.cpp
)

INSTALL(TARGETS 2out ARCHIVE DESTINATION lib)
INSTALL(DIRECTORY . DESTINATION include/2out FILES_MATCHING PATTERN "*.h")
