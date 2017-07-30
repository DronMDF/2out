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

TestSuiteTest::TestSuiteTest()
: tests(
	make_unique<TestNamed>(
		"TestSuiteTest",
		list<shared_ptr<const Test>>{
			make_shared<TestEqual>(
				make_shared<ReprTest>(
					make_unique<TestSuite>(
						list<shared_ptr<const Test>>{}
					)
				),
				"success"
			)
		}
	)
)
{
}

unique_ptr<const Result> TestSuiteTest::result() const
{
	return tests->result();
}
