// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <list>
#include <memory>
#include <2out.h>
#include "TextReportTest.h"
#include "TstSuiteTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const TextReport report(
		make_unique<TstSuite>(
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
				make_shared<const TextReportTest>(),
				make_shared<const TstSuiteTest>()
			}
		)
	);

	const auto report_string = report.asString();
	cout << report_string << endl;

	// @todo #4:15min Report should produce text and status.
	//  Detect status by test this is a wrong way.
	return report_string.find("SUCCESS") != string::npos ? 0 : -1;
}
