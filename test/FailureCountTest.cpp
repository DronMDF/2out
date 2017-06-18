// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FailureCountTest.h"
#include <Assertion.h>
#include <FailureCount.h>
#include <ResSuite.h>
#include <TstSimple.h>
#include <TstSuite.h>
#include <Failure.h>
#include <Success.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

class IsFailures final : public Assertion {
public:
	IsFailures(size_t count, const shared_ptr<const Result> &result)
		: count(count), result(result)
	{
	}

	shared_ptr<const AssertionResult> check() const override {
		// @todo #111:15min Name conflice class vs methos result.
		//  class result should be more concrete.
		shared_ptr<const AssertionResult> res;
		if (FailureCount(result).count() == count) {
			res = make_shared<Success>();
		} else {
			res = make_shared<Failure>();
		}
		return res;
	}

private:
	const size_t count;
	const shared_ptr<const Result> result;
};

FailureCountTest::FailureCountTest()
: tests(
	make_unique<const TstSuite>(
		"FailureCountTest",
		list<shared_ptr<const Test>>{
			make_shared<const TstSimple>(
				"Suite failures are sum of failure test",
				make_unique<const IsFailures>(
					1,
					make_unique<const ResSuite>(
						"One of Three is failed",
						list<shared_ptr<const Result>>{
							make_unique<const ResOkCase>(),
							make_unique<const ResFailureCase>(),
							make_unique<const ResOkCase>()
						}
					)
				)
			)
		}
	)
)
{
}

shared_ptr<const Result> FailureCountTest::result() const
{
	return tests->result();
}
