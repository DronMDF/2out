CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(2out)

ADD_LIBRARY(
	2out
	Error.cpp
	FailureCount.cpp
	Failure.cpp
	JUnitXmlReport.cpp
	ResSimple.cpp
	ResSuite.cpp
	ResTimed.cpp
	Success.cpp
	TestContainText.cpp
	TestCount.cpp
	TestEqual.cpp
	TextReport.cpp
	TstSuite.cpp
	TstTimed.cpp
)
