// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TstSuiteTest.h"
#include <Assertion.h>
#include <AssertionResult.h>
#include <FailureCount.h>
#include <TstSimple.h>
#include <TstSuite.h>
#include <Result.h>

using namespace std;
using namespace oout;

class IsTestSuccess final : public Assertion
{
public:
	explicit IsTestSuccess(unique_ptr<const Test> test)
		: test(move(test))
	{
	}

	shared_ptr<const AssertionResult> check() const override {
		return make_shared<AssertionResult>(FailureCount(test->result()).count() == 0);
	}
private:
	const unique_ptr<const Test> test;
};

TstSuiteTest::TstSuiteTest()
	: tests(make_unique<const TstSuite>(
		"TstSuiteTest",
		list<shared_ptr<const Test>>{
			make_shared<const TstSimple>(
				"Empty Suite always return success",
				make_unique<const IsTestSuccess>(
					make_unique<const TstSuite>(
						"Always success suite",
						list<shared_ptr<const Test>>{}
					)
				)
			)
		}
	))
{
}

shared_ptr<const Result> TstSuiteTest::result() const
{
	return tests->result();
}
