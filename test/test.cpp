// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <list>
#include <memory>
#include <CountError.h>
#include <CountFailure.h>
#include <JUnitXmlReport.h>
#include <ReprSigned.h>
#include <Result.h>
#include <TestEqual.h>
#include <TestSuite.h>
#include "CountErrorTest.h"
#include "CountFailureTest.h"
#include "CountTestTest.h"
#include "JUnitXmlReportTest.h"
#include "TestSuiteTest.h"
#include "TextReportTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const auto result = TestSuite(
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
			make_shared<const CountErrorTest>(),
			make_shared<const CountFailureTest>(),
			make_shared<const CountTestTest>(),
			make_shared<const JUnitXmlReportTest>(),
			make_shared<const TestSuiteTest>(),
			make_shared<const TextReportTest>()
		}
	).result();

	cout << JUnitXmlReport(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
