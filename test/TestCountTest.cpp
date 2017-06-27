// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestCountTest.h"
#include <Representation.h>
#include <ReprSigned.h>
#include <ResSuite.h>
#include <TestCount.h>
#include <TestEqual.h>
#include <TestNamed.h>
#include <TestSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

class TestCountRepr final : public Representation {
public:
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
	make_unique<TestNamed>(
		"TestCountTest",
		make_unique<TestSuite>(
			list<shared_ptr<const Test>>{
				make_shared<TestEqual>(
					make_shared<TestCountRepr>(
						make_unique<TestCount>(
							list<shared_ptr<const Result>>{
								make_unique<ResOkCase>(),
								make_unique<ResOkCase>(),
								make_unique<ResOkCase>()
							}
						)
					),
					make_shared<ReprSigned>(3)
				)
			}
		)
	)
)
{
}

shared_ptr<const Result> TestCountTest::result() const
{
	return tests->result();
}
