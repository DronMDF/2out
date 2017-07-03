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
	ResSimple.cpp
	ResSuite.cpp
	ResTimed.cpp
	Success.cpp
	TestContainText.cpp
	TestEqual.cpp
	TestNamed.cpp
	TestSafe.cpp
	TestStartsWith.cpp
	TestSuite.cpp
	TestTimed.cpp
	TextReport.cpp
)
