// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TextReportTest.h"
#include <2out/2out.h>
#include <2out/FailureResult.h>
#include <2out/NamedResult.h>
#include <2out/SuccessResult.h>
#include <2out/SuiteResult.h>
#include <2out/TestResult.h>

using namespace std;
using namespace oout;

TextReportTest::TextReportTest()
: tests(
	make_unique<NamedTest>(
		"TextReportTest",
		make_shared<ContainTest>(
			make_unique<TextReport>(
				make_shared<NamedResult>(
					"run test",
					make_shared<TestResult>(make_shared<FailureResult>())
				)
			),
			"[ RUN      ] run test"
		),
		make_shared<ContainTest>(
			make_unique<TextReport>(
				make_shared<NamedResult>(
					"ok test",
					make_shared<TestResult>(make_shared<SuccessResult>())
				)
			),
			"[       OK ] ok test"
		),
		make_shared<ContainTest>(
			make_unique<TextReport>(
				make_shared<NamedResult>(
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
				make_unique<NamedResult>(
					"SUITE",
					make_unique<SuiteResult>(
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
