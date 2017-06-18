CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(2out)

ADD_LIBRARY(
	2out
	Error.cpp
	FailureCount.cpp
	Failure.cpp
	IsEqual.cpp
	JUnitXmlReport.cpp
	ResSimple.cpp
	ResSuite.cpp
	ResTimed.cpp
	Success.cpp
	TestCount.cpp
	TextReport.cpp
	TstSimple.cpp
	TstSuite.cpp
	TstTimed.cpp
)
