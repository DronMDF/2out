// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TextReportTest.h"
#include <list>
#include <ResSuite.h>
#include <TestContainText.h>
#include <TextReport.h>
#include <TstSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

TextReportTest::TextReportTest()
: tests(
	make_unique<const TstSuite>(
		"TextReportTest",
		list<shared_ptr<const Test>>{
			make_shared<TestContainText>(
				make_unique<TextReport>(
					make_unique<ResFailureCase>("run test")
				),
				"[ RUN      ] run test"
			),
			make_shared<TestContainText>(
				make_unique<TextReport>(
					make_unique<ResOkCase>("ok test")
				),
				"[       OK ] ok test"
			),
			make_shared<TestContainText>(
				make_unique<TextReport>(
					make_unique<ResFailureCase>("fail test")
				),
				"[  FAILED  ] fail test"
			),
			make_shared<TestContainText>(
				make_unique<TextReport>(
					make_unique<ResOkCase>()
				),
				"[==========] Running"
			),
			make_shared<TestContainText>(
				make_unique<TextReport>(
					make_unique<ResOkCase>()
				),
				"[==========] 1 tests ran"
			),
			make_shared<TestContainText>(
				make_unique<TextReport>(
					make_unique<ResSuite>(
						"SUITE",
						list<shared_ptr<const Result>>{
							make_shared<ResOkCase>(),
							make_shared<ResOkCase>()
						}
					)
				),
				"[----------] 2 test from SUITE"
			)
		}
	)
)
{
}

shared_ptr<const Result> TextReportTest::result() const
{
	return tests->result();
}
