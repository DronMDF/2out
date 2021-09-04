// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "OoutReportTextTest.h"
#include <2out/2out.h>
#include <2out/FailureResult.h>
#include <2out/ErrorResult.h>
#include <2out/NamedResult.h>
#include <2out/SuccessResult.h>
#include <2out/SuiteResult.h>
#include <2out/TestResult.h>

using namespace std;
using namespace oout;

OoutReportTextTest::OoutReportTextTest()
: dirty::Test(
	"OoutReportText tests",
	make_shared<NamedTest>(
		"OoutReportText should show summary string",
		make_shared<OoutReportText>(
			make_shared<TestResult>(make_shared<SuccessResult>())
		),
		make_shared<ContainMatch>("0 of 1 tests failed")
	),
	make_shared<NamedTest>(
		"OoutReportText should show failed test",
		make_shared<OoutReportText>(
			make_shared<NamedResult>(
				"Test name",
				make_shared<TestResult>(make_shared<FailureResult>("failure"))
			)
		),
		make_shared<ContainMatch>("FAILURE: Test name"),
		make_shared<ContainMatch>("failure"),
		make_shared<ContainMatch>("1 of 1 tests failed")
	),
	make_shared<NamedTest>(
		"OoutReportText should show error test",
		make_shared<OoutReportText>(
			make_shared<NamedResult>(
				"Test name",
				make_shared<TestResult>(make_shared<ErrorResult>("error"))
			)
		),
		make_shared<ContainMatch>("ERROR: Test name"),
		make_shared<ContainMatch>("error"),
		make_shared<ContainMatch>("1 of 1 tests failed")
	),
	make_shared<NamedTest>(
		"OoutReportText should show suite tests",
		make_shared<OoutReportText>(
			make_shared<SuiteResult>(
				make_shared<NamedResult>(
					"Suite failed test",
					make_shared<TestResult>(make_shared<ErrorResult>())
				)
			)
		),
		make_shared<ContainMatch>("ERROR: Suite failed test")
	)
)
{
}
