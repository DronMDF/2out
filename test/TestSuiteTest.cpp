// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestSuiteTest.h"
#include <FailureCount.h>
#include <Representation.h>
#include <TestEqual.h>
#include <TestNamed.h>
#include <TestSuite.h>

using namespace std;
using namespace oout;

class TestStatusRepr final : public Representation {
public:
	explicit TestStatusRepr(const shared_ptr<const Test> &test)
		: test(test)
	{
	}

	string asString() const override
	{
		return FailureCount(test->result()).count() == 0 ? "success" : "failure";
	}
private:
	const shared_ptr<const Test> test;
};

TestSuiteTest::TestSuiteTest()
: tests(
	make_unique<TestNamed>(
		"TestSuiteTest",
		make_unique<TestSuite>(
			list<shared_ptr<const Test>>{
				make_shared<TestEqual>(
					make_shared<TestStatusRepr>(
						make_unique<TestSuite>(
							list<shared_ptr<const Test>>{}
						)
					),
					"success"
				)
			}
		)
	)
)
{
}

shared_ptr<const Result> TestSuiteTest::result() const
{
	return tests->result();
}
