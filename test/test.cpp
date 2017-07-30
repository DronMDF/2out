// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <list>
#include <memory>
#include <2out/CountError.h>
#include <2out/CountFailure.h>
#include <2out/JUnitXmlReport.h>
#include <2out/ReprSigned.h>
#include <2out/Result.h>
#include <2out/TestEqual.h>
#include <2out/TestSuite.h>
#include "CountErrorTest.h"
#include "CountFailureTest.h"
#include "CountTestTest.h"
#include "JUnitXmlReportTest.h"
#include "ReprPrintableTest.h"
#include "TestSkippedTest.h"
#include "TestStartsWithTest.h"
#include "TestSuiteTest.h"
#include "TextReportTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const shared_ptr<const Result> result = TestSuite(
		list<shared_ptr<const Test>>{
			make_shared<TestEqual>(
				make_shared<ReprSigned>(2 * 2),
				make_shared<ReprSigned>(4)
			),
			make_shared<const TestSuite>(
				list<shared_ptr<const Test>>{
					make_shared<TestEqual>(
						make_shared<ReprSigned>(2 + 2),
						make_shared<ReprSigned>(4)
					)
				}
			),
			make_unique<CountErrorTest>(),
			make_unique<CountFailureTest>(),
			make_unique<CountTestTest>(),
			make_unique<JUnitXmlReportTest>(),
			make_unique<ReprPrintableTest>(),
			make_unique<TestSkippedTest>(),
			make_unique<TestStartsWithTest>(),
			make_unique<TestSuiteTest>(),
			make_unique<TextReportTest>()
		}
	).result();

	cout << JUnitXmlReport(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
