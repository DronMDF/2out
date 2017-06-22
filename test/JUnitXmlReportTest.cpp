// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "JUnitXmlReportTest.h"
#include <list>
#include <Assertion.h>
#include <Failure.h>
#include <Format.h>
#include <JUnitXmlReport.h>
#include <ResSuite.h>
#include <StringRepr.h>
#include <Success.h>
#include <TestContainText.h>
#include <TstSimple.h>
#include <TstSuite.h>
#include <TstTemplate.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

// @todo #135:15min This class is like of IsTextInReport from TextReportTest.
//  Need thinking about standart assertions.
class IsTextInJUnitXmlReport final : public Assertion {
public:
	IsTextInJUnitXmlReport(const string &text, unique_ptr<const JUnitXmlReport> report)
		: text(text), report(move(report))
	{
	}

	shared_ptr<const AssertionResult> check() const override {
		shared_ptr<const AssertionResult> result;
		if (report->asString().find(text) != string::npos) {
			result = make_shared<Success>();
		} else {
			result = make_shared<Failure>();
		}
		return result;
	}

private:
	const string text;
	const unique_ptr<const JUnitXmlReport> report;
};

class IsTextContain final {
public:
	explicit IsTextContain(const string &text)
		: text(text)
	{
	}

	template<typename O>
	shared_ptr<const AssertionResult> check(const shared_ptr<const O> &object) const {
		shared_ptr<const AssertionResult> result;
		if (object->asString().find(text) != string::npos) {
			result = make_shared<Success>();
		} else {
			result = make_shared<Failure>();
		}
		return result;
	}

private:
	const string text;
};

class ReportAsString final : public StringRepr {
public:
	explicit ReportAsString(const shared_ptr<const JUnitXmlReport> &report)
		: report(report)
	{
	}

	string asString() const override {
		return report->asString();
	}

private:
	const shared_ptr<const JUnitXmlReport> report;
};

JUnitXmlReportTest::JUnitXmlReportTest()
: tests(
	make_unique<const TstSuite>(
		"JUnitXmlReportTest",
		list<shared_ptr<const Test>>{
			make_shared<const TstSimple>(
				"Report contain error tag",
				make_unique<const IsTextInJUnitXmlReport>(
					"<error",
					make_unique<const JUnitXmlReport>(
						make_unique<ResErrorCase>()
					)
				)
			),
			make_shared<TstTemplate<JUnitXmlReport, IsTextContain>>(
				"Report contain error end tag",
				make_unique<JUnitXmlReport>(
					make_unique<ResErrorCase>()
				),
				make_unique<IsTextContain>("</error>")
			),
			make_shared<TestContainText>(
				make_shared<ReportAsString>(
					make_unique<JUnitXmlReport>(
						make_unique<ResFailureCase>()
					)
				),
				"<failure"
			)
		}
	)
)
{
}

shared_ptr<const Result> JUnitXmlReportTest::result() const
{
	return tests->result();
}
