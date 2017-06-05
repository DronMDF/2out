// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestCountTest.h"
#include <Assertion.h>
#include <TestCount.h>
#include <ResSuite.h>
#include <TstSimple.h>
#include <TstSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

// @todo #82:15min class is similar to IsFailures.
//  Need to thinking about universal assertion
class IsTests final : public Assertion {
public:
	IsTests(size_t count, const shared_ptr<const Result> &result)
		: count(count), result(result)
	{
	}

	bool valid() const override {
		return TestCount(result).count() == count;
	}

private:
	const size_t count;
	const shared_ptr<const Result> result;
};

TestCountTest::TestCountTest()
: tests(
	make_unique<const TstSuite>(
		"TestCountTest",
		list<shared_ptr<const Test>>{
			make_shared<const TstSimple>(
				"TestCount count only simple tests",
				make_unique<const IsTests>(
					3,
					make_unique<const ResSuite>(
						"Three tests",
						0,
						list<shared_ptr<const Result>>{
							make_unique<const ResOkCase>(),
							make_unique<const ResOkCase>(),
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

shared_ptr<const Result> TestCountTest::result() const
{
	return tests->result();
}
