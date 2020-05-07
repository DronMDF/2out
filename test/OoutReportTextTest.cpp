// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "OoutReportTextTest.h"
#include <2out/2out.h>
#include <2out/OoutReportText.h>
#include <2out/SuccessResult.h>
#include <2out/TestResult.h>

using namespace std;
using namespace oout;

OoutReportTextTest::OoutReportTextTest()
: dirty::Test(
	make_shared<NamedTest>(
		"OoutReportText should show summary string",
		make_shared<OoutReportText>(
			make_shared<TestResult>(make_shared<SuccessResult>())
		),
		make_shared<ContainMatch>(
			"0 of 1 tests failed"
		)
	)
)
{
}
