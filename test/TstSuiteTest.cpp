// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TstSuiteTest.h"
#include <FailureCount.h>
#include <StringRepr.h>
#include <TestEqual.h>
#include <TstSuite.h>

using namespace std;
using namespace oout;

class TestStatusRepr final : public StringRepr {
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

TstSuiteTest::TstSuiteTest()
	: tests(make_unique<const TstSuite>(
		"TstSuiteTest",
		list<shared_ptr<const Test>>{
			make_shared<TestEqual>(
				make_shared<TestStatusRepr>(
					make_unique<TstSuite>(
						"Always success suite",
						list<shared_ptr<const Test>>{}
					)
				),
				string("success")
			)
		}
	))
{
}

shared_ptr<const Result> TstSuiteTest::result() const
{
	return tests->result();
}
