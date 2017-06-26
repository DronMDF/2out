// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FailureCountTest.h"
#include <FailureCount.h>
#include <Representation.h>
#include <ReprSigned.h>
#include <ResSuite.h>
#include <TestEqual.h>
#include <TestSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

class FailureCountRepr final : public Representation {
public:
	explicit FailureCountRepr(const shared_ptr<const FailureCount> &count)
		: count(count)
	{
	}

	string asString() const override
	{
		return to_string(count->count());
	}
private:
	const shared_ptr<const FailureCount> count;
};

FailureCountTest::FailureCountTest()
: tests(
	make_unique<const TestSuite>(
		"FailureCountTest",
		list<shared_ptr<const Test>>{
			make_shared<TestEqual>(
				make_shared<FailureCountRepr>(
					make_unique<FailureCount>(
						list<shared_ptr<const Result>>{
							make_unique<ResOkCase>(),
							make_unique<ResFailureCase>(),
							make_unique<ResOkCase>()
						}
					)
				),
				make_shared<ReprSigned>(1)
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
