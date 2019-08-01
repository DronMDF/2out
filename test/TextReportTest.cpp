// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TextReportTest.h"
#include <list>
#include <2out/2out.h>
#include <2out/ResNamed.h>
#include <2out/ResSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

TextReportTest::TextReportTest()
	: tests(
		make_unique<TestNamed>(
			"TextReportTest",
			make_shared<ContainTest>(
				make_unique<TextReport>(
					make_unique<ResFailureCase>("run test")
				),
				"[ RUN      ] run test"
			),
			make_shared<ContainTest>(
				make_unique<TextReport>(
					make_unique<ResOkCase>("ok test")
				),
				"[       OK ] ok test"
			),
			make_shared<ContainTest>(
				make_unique<TextReport>(
					make_unique<ResFailureCase>("fail test")
				),
				"[  FAILED  ] fail test"
			),
			make_shared<ContainTest>(
				make_unique<TextReport>(
					make_unique<ResOkCase>()
				),
				"[==========] Running"
			),
			make_shared<ContainTest>(
				make_unique<TextReport>(
					make_unique<ResOkCase>()
				),
				"[==========] 1 tests ran"
			),
			make_shared<ContainTest>(
				make_unique<TextReport>(
					make_unique<ResNamed>(
						"SUITE",
						make_unique<ResSuite>(
							make_shared<ResOkCase>(),
							make_shared<ResOkCase>()
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
