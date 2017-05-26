// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TextReportTest.h"
#include <list>
#include <Assertion.h>
#include <ResSimple.h>
#include <TextReport.h>
#include <TstSimple.h>
#include <TstSuite.h>

using namespace std;
using namespace oout;

class IsTextInReport final : public Assertion {
public:
	explicit IsTextInReport(const string &text, unique_ptr<const TextReport> report)
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

class TstSuccess final : public Test {
public:
	shared_ptr<const Result> result() const override {
		return make_shared<const ResSimple>(true);
	}
};

TextReportTest::TextReportTest()
: tests(
	make_unique<const TstSuite>(
		"TextReportTest",
		list<shared_ptr<const Test>>{
			make_shared<const TstSimple>(
				"SUCCESS in report if tests success",
				make_unique<const IsTextInReport>(
					"SUCCESS",
					make_unique<const TextReport>(
						make_unique<const TstSuccess>()
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
