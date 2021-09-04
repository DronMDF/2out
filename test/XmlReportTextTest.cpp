// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "XmlReportTextTest.h"
#include <list>
#include <2out/2out.h>
#include <2out/ErrorResult.h>
#include <2out/FailureResult.h>
#include <2out/SuiteResult.h>
#include <2out/TestResult.h>

using namespace std;
using namespace oout;

XmlReportTextTest::XmlReportTextTest()
: tests(
	make_unique<NamedTest>(
		"XmlReportTextTest",
		make_shared<ContainTest>(
			make_unique<XmlReportText>(
				make_shared<TestResult>(make_shared<ErrorResult>())
			),
			"<error"
		),
		make_shared<ContainTest>(
			make_unique<XmlReportText>(
				make_shared<TestResult>(make_shared<ErrorResult>())
			),
			"</error>"
		),
		make_shared<ContainTest>(
			make_unique<XmlReportText>(
				make_shared<TestResult>(make_shared<FailureResult>())
			),
			"<failure"
		),
		make_shared<NamedTest>(
			"Escaping in failure",
			make_shared<ContainTest>(
				make_unique<XmlReportText>(
					make_unique<TestResult>(
						make_unique<FailureResult>("<tag>")
					)
				),
				"failure><![CDATA[<tag>]]"
			)
		),
		make_shared<NamedTest>(
			"Escaping in error",
			make_shared<ContainTest>(
				make_unique<XmlReportText>(
					make_unique<TestResult>(
						make_unique<ErrorResult>("&amp;")
					)
				),
				"error><![CDATA[&amp;]]"
			)
		),
		make_shared<NamedTest>(
			"Count of errors in suite",
			make_shared<ContainTest>(
				make_unique<XmlReportText>(
					make_unique<SuiteResult>(
						make_shared<TestResult>(
							make_shared<ErrorResult>()
						)
					)
				),
				"errors='1'"
			)
		)
	)
)
{
}

unique_ptr<const Result> XmlReportTextTest::result() const
{
	return tests->result();
}
