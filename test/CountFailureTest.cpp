// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CountFailureTest.h"
#include <CountFailure.h>
#include <Representation.h>
#include <ReprSigned.h>
#include <ResSuite.h>
#include <TestEqual.h>
#include <TestNamed.h>
#include <TestSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

class CountFailureRepr final : public Representation {
public:
	explicit CountFailureRepr(const shared_ptr<const CountFailure> &count)
		: count(count)
	{
	}

	string asString() const override
	{
		return to_string(count->count());
	}
private:
	const shared_ptr<const CountFailure> count;
};

CountFailureTest::CountFailureTest()
: tests(
	make_unique<TestNamed>(
		"CountFailureTest",
		list<shared_ptr<const Test>>{
			make_shared<TestEqual>(
				make_shared<CountFailureRepr>(
					make_unique<CountFailure>(
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

shared_ptr<const Result> CountFailureTest::result() const
{
	return tests->result();
}
