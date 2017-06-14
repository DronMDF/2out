// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TextReportTest.h"
#include <list>
#include <Assertion.h>
#include <Format.h>
#include <ResSuite.h>
#include <TextReport.h>
#include <TstSimple.h>
#include <TstSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

class IsTextInReport final : public Assertion {
public:
	IsTextInReport(const string &text, unique_ptr<const TextReport> report)
		: text(text), report(move(report))
	{
	}

	bool valid() const override {
		return report->asString().find(text) != string::npos;
	}

private:
	const string text;
	const unique_ptr<const TextReport> report;
};

TextReportTest::TextReportTest()
: tests(
	make_unique<const TstSuite>(
		"TextReportTest",
		list<shared_ptr<const Test>>{
			make_shared<const TstSimple>(
				"Report contain RUN of testcase",
				make_unique<const IsTextInReport>(
					"[ RUN      ] run test",
					make_unique<const TextReport>(
						make_unique<const ResFailureCase>("run test")
					)
				)
			),
			make_shared<const TstSimple>(
				"Report contain OK of success testcase",
				make_unique<const IsTextInReport>(
					"[       OK ] ok test",
					make_unique<const TextReport>(
						make_unique<const ResOkCase>("ok test")
					)
				)
			),
			make_shared<const TstSimple>(
				"Report contain FAILED of failed test",
				make_unique<const IsTextInReport>(
					"[  FAILED  ] fail test",
					make_unique<const TextReport>(
						make_unique<const ResFailureCase>("fail test")
					)
				)
			),
			make_shared<const TstSimple>(
				"Test should contain prolog",
				make_unique<const IsTextInReport>(
					"[==========] Running",
					make_unique<const TextReport>(
						make_unique<const ResOkCase>("any")
					)
				)
			),
			make_shared<const TstSimple>(
				"Test should contain epilog",
				make_unique<const IsTextInReport>(
					"[==========] 1 tests ran",
					make_unique<const TextReport>(
						make_unique<const ResOkCase>("any")
					)
				)
			),
			make_shared<const TstSimple>(
				"Test suite line show count of tests",
				make_unique<const IsTextInReport>(
					"[----------] 2 test from SUITE",
					make_unique<const TextReport>(
						make_unique<const ResSuite>(
							"SUITE",
							list<shared_ptr<const Result>>{
								make_shared<const ResOkCase>(),
								make_shared<const ResOkCase>()
							}
						)
					)
				)
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
