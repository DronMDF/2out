CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(2out)

ADD_LIBRARY(
	2out
	FailureCount.cpp
	IsEqual.cpp
	JUnitXmlReport.cpp
	ResSimple.cpp
	ResSuite.cpp
	TestCount.cpp
	TextReport.cpp
	TstSimple.cpp
	TstSuite.cpp
)
