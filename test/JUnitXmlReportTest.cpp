// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "JUnitXmlReportTest.h"
#include <list>
#include <2out/Error.h>
#include <2out/Failure.h>
#include <2out/JUnitXmlReport.h>
#include <2out/ResSuite.h>
#include <2out/ResTest.h>
#include <2out/TestContainText.h>
#include <2out/TestNamed.h>
#include <2out/TestSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

JUnitXmlReportTest::JUnitXmlReportTest()
: tests(
	make_unique<TestNamed>(
		"JUnitXmlReportTest",
		list<shared_ptr<const Test>>{
			make_shared<TestContainText>(
				make_unique<JUnitXmlReport>(
					make_unique<ResErrorCase>()
				),
				"<error"
			),
			make_shared<TestContainText>(
				make_unique<JUnitXmlReport>(
					make_unique<ResErrorCase>()
				),
				"</error>"
			),
			make_shared<TestContainText>(
				make_unique<JUnitXmlReport>(
					make_unique<ResFailureCase>()
				),
				"<failure"
			),
			make_shared<TestNamed>(
				"Escaping in failure",
				make_shared<TestContainText>(
					make_unique<JUnitXmlReport>(
						make_unique<ResTest>(
							make_unique<Failure>("<tag>")
						)
					),
					"failure><![CDATA[<tag>]]"
				)
			),
			make_shared<TestNamed>(
				"Escaping in error",
				make_shared<TestContainText>(
					make_unique<JUnitXmlReport>(
						make_unique<ResTest>(
							make_unique<Error>("&amp;")
						)
					),
					"error><![CDATA[&amp;]]"
				)
			),
			make_shared<TestNamed>(
				"Count of errors in suite",
				make_shared<TestContainText>(
					make_unique<JUnitXmlReport>(
						make_unique<ResSuite>(
							list<shared_ptr<const Result>>{
								make_unique<ResErrorCase>()
							}
						)
					),
					"errors='1'"
				)
			)
		}
	)
)
{
}

unique_ptr<const Result> JUnitXmlReportTest::result() const
{
	return tests->result();
}
