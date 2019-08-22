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
	ResSuite.cpp
	ResTimed.cpp
	SuccessResult.cpp
	TestResult.cpp

	# Text
	JUnitXmlReport.cpp
	ReprCallable.cpp
	SignedText.cpp
	StringText.cpp
	TextReport.cpp

	# Misc
	CountError.cpp
	CountFailure.cpp
)

INSTALL(TARGETS 2out ARCHIVE DESTINATION lib)
INSTALL(DIRECTORY . DESTINATION include/2out FILES_MATCHING PATTERN "*.h")
