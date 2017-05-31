// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TextReportTest.h"
#include <list>
#include <Assertion.h>
#include <Result.h>
#include <TextReport.h>
#include <TstSimple.h>
#include <TstSuite.h>

using namespace std;
using namespace oout;

class IsTextInReport final : public Assertion {
public:
	IsTextInReport(
		const string &text,
		unique_ptr<TextReport> report,
		unique_ptr<const Result> result
	) : text(text), report(move(report)), result(move(result))
	{
	}

	bool valid() const override {
		result->print(report.get());
		return report->asString().find(text) != string::npos;
	}

private:
	const string text;
	const unique_ptr<TextReport> report;
	const unique_ptr<const Result> result;
};

TextReportTest::TextReportTest()
: tests(
	make_unique<const TstSuite>(
		"TextReportTest",
		list<shared_ptr<const Test>>{
			make_shared<const TstSimple>(
				"SUCCESS in report if tests success",
				// @todo #46:15min This test is little fake.
				//  SUCCESS is a output test name, not a status
				make_unique<const IsTextInReport>(
					"SUCCESS",
					make_unique<TextReport>(),
					make_unique<const Result>(
						"SUCCESS",
						map<string, string>{
							make_pair("failures", "0")
						},
						list<shared_ptr<const Result>>{}
					)
				)
			),
			make_shared<const TstSimple>(
				"FAILURE in report if tests failure",
				// @todo #46:15min This test is little fake.
				//  FAILURE is a output test name, not a status
				make_unique<const IsTextInReport>(
					"FAILURE",
					make_unique<TextReport>(),
					make_unique<const Result>(
						"FAILURE",
						map<string, string>{
							make_pair("failures", "1")
						},
						list<shared_ptr<const Result>>{}
					)
				)
			),
			make_shared<const TstSimple>(
				"Report contain RUN of testcase",
				make_unique<const IsTextInReport>(
					"[ RUN      ] run test",
					make_unique<TextReport>(),
					// @todo #53:15min Add FakeResult for testing
					make_unique<const Result>(
						"testcase",
						map<string, string>{
							make_pair("name", "run test"),
							make_pair("failures", "0")
						},
						list<shared_ptr<const Result>>{}
					)
				)
			),
			make_shared<const TstSimple>(
				"Report contain OK of success testcase",
				make_unique<const IsTextInReport>(
					"[       OK ] ok test",
					make_unique<TextReport>(),
					make_unique<const Result>(
						"testcase",
						map<string, string>{
							make_pair("name", "ok test"),
							make_pair("failures", "0")
						},
						list<shared_ptr<const Result>>{}
					)
				)
			),
			make_shared<const TstSimple>(
				"Report contain FAIL of failed testcase",
				make_unique<const IsTextInReport>(
					"[     FAIL ] fail test",
					make_unique<TextReport>(),
					make_unique<const Result>(
						"testcase",
						map<string, string>{
							make_pair("name", "fail test"),
							make_pair("failures", "1")
						},
						list<shared_ptr<const Result>>{}
					)
				)
			),
		}
	)
)
{
}

shared_ptr<const Result> TextReportTest::result() const
{
	return tests->result();
}
