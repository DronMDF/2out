CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(test)

ADD_EXECUTABLE(
	test_runner
	FailureCountTest.cpp
	ResFakes.cpp
	test.cpp
	TestCountTest.cpp
	TextReportTest.cpp
	TstSuiteTest.cpp
)
TARGET_LINK_LIBRARIES(
	test_runner
	2out
)

ADD_CUSTOM_COMMAND(
	TARGET test_runner
	PRE_BUILD
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/shippable/testresults
)

# @todo #54:15min shippable path - this is shippable lock in sources
#  test_runner can write report to file, file placement define in shippable.yml (copy)
ADD_TEST(
	NAME test
	COMMAND sh -c "./test_runner > ${CMAKE_BINARY_DIR}/shippable/testresults/result.xml"
)
