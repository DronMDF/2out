// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestSuiteTest.h"
#include <2out/2out.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

TestSuiteTest::TestSuiteTest()
	: tests(
		make_unique<TestNamed>(
			"TestSuiteTest",
			make_shared<TestNamed>(
				"Test suite with empty list is always success",
				make_shared<TestEqual>(
					make_shared<ReprTest>(
						make_unique<TestSuite>(
							list<shared_ptr<const Test>>{}
						)
					),
					"success"
				)
			),
			make_shared<TestNamed>(
				"Test suite give tests as variadic args",
				make_shared<TestEqual>(
					make_shared<ReprTest>(
						make_unique<TestSuite>(
							make_shared<TestEqual>("1", "1"),
							make_shared<TestEqual>("2", "2"),
							make_shared<TestEqual>("3", "3")
						)
					),
					"success"
				)
			)
		)
	)
{
}

unique_ptr<const Result> TestSuiteTest::result() const
{
	return tests->result();
}
