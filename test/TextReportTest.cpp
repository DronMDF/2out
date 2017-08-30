// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TextReportTest.h"
#include <list>
#include <2out/ResNamed.h>
#include <2out/ResSuite.h>
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include <2out/TestSuite.h>
#include <2out/TextReport.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

TextReportTest::TextReportTest()
: tests(
	make_unique<TestNamed>(
		"TextReportTest",
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
				make_unique<ResNamed>(
					"SUITE",
					make_unique<ResSuite>(
						list<shared_ptr<const Result>>{
							make_unique<ResOkCase>(),
							make_unique<ResOkCase>()
						}
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
