// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestCountTest.h"
#include <ResSuite.h>
#include <StringRepr.h>
#include <TestEqual.h>
#include <TestCount.h>
#include <TstSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

class TestCountRepr final : public StringRepr {
public:
	explicit TestCountRepr(unique_ptr<const Result> result)
		: TestCountRepr(make_shared<TestCount>(move(result)))
	{
	}

	explicit TestCountRepr(const shared_ptr<const TestCount> &count)
		: count(count)
	{
	}

	string asString() const override
	{
		return to_string(count->count());
	}
private:
	const shared_ptr<const TestCount> count;
};

TestCountTest::TestCountTest()
: tests(
	make_unique<const TstSuite>(
		"TestCountTest",
		list<shared_ptr<const Test>>{
			make_shared<TestEqual>(
				make_shared<TestCountRepr>(
					make_unique<ResSuite>(
						"Three tests",
						list<shared_ptr<const Result>>{
							make_unique<ResOkCase>(),
							make_unique<ResOkCase>(),
							make_unique<ResOkCase>()
						}
					)
				),
				"3"
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
