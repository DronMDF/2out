CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(2out)

ADD_LIBRARY(
	2out
	CountError.cpp
	CountFailure.cpp
	CountTest.cpp
	Error.cpp
	Failure.cpp
	JUnitXmlReport.cpp
	ReprSigned.cpp
	ReprString.cpp
	ResNamed.cpp
	ResSuite.cpp
	ResTest.cpp
	ResTimed.cpp
	Success.cpp
	TestContainText.cpp
	TestEqual.cpp
	TestNamed.cpp
	TestSkipped.cpp
	TestSafe.cpp
	TestStartsWith.cpp
	TestSuite.cpp
	TestTimed.cpp
	TextReport.cpp
)

INSTALL(TARGETS 2out ARCHIVE DESTINATION lib)
INSTALL(DIRECTORY . DESTINATION include/2out FILES_MATCHING PATTERN "*.h")
