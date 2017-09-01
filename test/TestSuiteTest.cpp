// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestSuiteTest.h"
#include <2out/Result.h>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <2out/TestSuite.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

// @todo #265 TestSuite without test is error.
//  User can pass empty list, but not can create empty Suite
TestSuiteTest::TestSuiteTest()
	: tests(
		make_unique<TestNamed>(
			"TestSuiteTest",
			make_shared<TestEqual>(
				make_shared<ReprTest>(
					make_unique<TestSuite>(
						list<shared_ptr<const Test>>{
}
					)
				),
				"success"
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
