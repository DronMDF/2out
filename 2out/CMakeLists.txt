CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(2out)

ADD_LIBRARY(
	2out
	AllMatch.cpp
	ContainMatch.cpp
	ContainTest.cpp
	CondResult.cpp
	CountError.cpp
	CountFailure.cpp
	CountTest.cpp
	EndsWithTest.cpp
	EqualMatch.cpp
	EqualTest.cpp
	Error.cpp
	Failure.cpp
	JUnitXmlReport.cpp
	MatchTest.cpp
	NamedTest.cpp
	ReprCallable.cpp
	ReprSigned.cpp
	ReprString.cpp
	ResNamed.cpp
	ResSuite.cpp
	ResTest.cpp
	ResTimed.cpp
	SafeTest.cpp
	SkippedTest.cpp
	StartsWithTest.cpp
	Success.cpp
	SuiteTest.cpp
	TimedTest.cpp
	TextReport.cpp
	dirty/Test.cpp
)

INSTALL(TARGETS 2out ARCHIVE DESTINATION lib)
INSTALL(DIRECTORY . DESTINATION include/2out FILES_MATCHING PATTERN "*.h")
