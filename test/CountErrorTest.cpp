// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CountErrorTest.h"
#include <CountError.h>
#include <Representation.h>
#include <ReprSigned.h>
#include <ResSuite.h>
#include <TestEqual.h>
#include <TestNamed.h>
#include <TestSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

class CountErrorRepr final : public Representation {
public:
	explicit CountErrorRepr(const shared_ptr<const CountError> &count)
		: count(count)
	{
	}

	string asString() const override
	{
		return to_string(count->count());
	}
private:
	const shared_ptr<const CountError> count;
};

CountErrorTest::CountErrorTest()
: tests(
	make_unique<TestNamed>(
		"CountErrorTest",
		list<shared_ptr<const Test>>{
			make_unique<TestNamed>(
				"One error in set",
				make_shared<TestEqual>(
					make_shared<CountErrorRepr>(
						make_unique<CountError>(
							list<shared_ptr<const Result>>{
								make_unique<ResOkCase>(),
								make_unique<ResFailureCase>(),
								make_unique<ResErrorCase>()
							}
						)
					),
					make_shared<ReprSigned>(1)
				)
			)
		}
	)
)
{
}

shared_ptr<const Result> CountErrorTest::result() const
{
	return tests->result();
}
