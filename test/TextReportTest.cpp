// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TextReportTest.h"
#include <2out/2out.h>
#include <2out/FailureResult.h>
#include <2out/ResNamed.h>
#include <2out/ResSuite.h>
#include <2out/SuccessResult.h>
#include <2out/TestResult.h>

using namespace std;
using namespace oout;

TextReportTest::TextReportTest()
: tests(
	make_unique<NamedTest>(
		"TextReportTest",
		make_shared<ContainTest>(
			make_unique<TextReport>(
				make_shared<ResNamed>(
					"run test",
					make_shared<TestResult>(make_shared<FailureResult>())
				)
			),
			"[ RUN      ] run test"
		),
		make_shared<ContainTest>(
			make_unique<TextReport>(
				make_shared<ResNamed>(
					"ok test",
					make_shared<TestResult>(make_shared<SuccessResult>())
				)
			),
			"[       OK ] ok test"
		),
		make_shared<ContainTest>(
			make_unique<TextReport>(
				make_shared<ResNamed>(
					"fail test",
					make_shared<TestResult>(make_shared<FailureResult>())
				)
			),
			"[  FAILED  ] fail test"
		),
		make_shared<ContainTest>(
			make_unique<TextReport>(
				make_shared<TestResult>(make_shared<SuccessResult>())
			),
			"[==========] Running"
		),
		make_shared<ContainTest>(
			make_unique<TextReport>(
				make_shared<TestResult>(make_shared<SuccessResult>())
			),
			"[==========] 1 tests ran"
		),
		make_shared<ContainTest>(
			make_unique<TextReport>(
				make_unique<ResNamed>(
					"SUITE",
					make_unique<ResSuite>(
						make_shared<TestResult>(
							make_shared<SuccessResult>()
						),
						make_shared<TestResult>(
							make_shared<SuccessResult>()
						)
					)
				)
			),
			"[----------] 2 test from SUITE"
		)
	)
)
{
}

unique_ptr<const Result> TextReportTest::result() const
{
	return tests->result();
}
