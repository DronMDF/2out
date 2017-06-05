// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <list>
#include <memory>
#include <2out.h>
#include <FailureCount.h>
#include <Result.h>
#include "FailureCountTest.h"
#include "TestCountTest.h"
#include "TextReportTest.h"
#include "TstSuiteTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const auto result = TstSuite(
		"Example suite",
		list<shared_ptr<const Test>>{
			make_shared<const TstSimple>(
				"2 * 2 should be equal 4",
				make_unique<const IsEqual>(2 * 2, 4)
			),
			make_shared<const TstSuite>(
				"Sub Suite",
				list<shared_ptr<const Test>>{
					make_shared<const TstSimple>(
						"2 + 2 should be equal 4",
						make_unique<const IsEqual>(2 + 2, 4)
					)
				}
			),
			make_shared<const FailureCountTest>(),
			make_shared<const TestCountTest>(),
			make_shared<const TextReportTest>(),
			make_shared<const TstSuiteTest>()
		}
	).result();

	cout << TextReport(result).asString() << endl;

	return FailureCount(result).count() == 0 ? 0 : -1;
}
