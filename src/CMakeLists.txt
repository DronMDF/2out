CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(2out)

ADD_LIBRARY(
	2out
	IsEqual.cpp
	Result.cpp
	ResSimple.cpp
	ResSuite.cpp
	TextReport.cpp
	TstSimple.cpp
	TstSuite.cpp
)
