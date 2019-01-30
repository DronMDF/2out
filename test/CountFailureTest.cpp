// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CountFailureTest.h"
#include <2out/CountFailure.h>
#include <2out/Representation.h>
#include <2out/ReprSigned.h>
#include <2out/ResSuite.h>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <2out/TestSuite.h>
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
			make_shared<TestEqual>(
				make_shared<CountFailureRepr>(
					make_unique<CountFailure>(
						make_unique<ResSuite>(
							make_shared<ResOkCase>(),
							make_shared<ResFailureCase>(),
							make_shared<ResOkCase>()
						)
					)
				),
				"1"
			)
		)
	)
{
}

unique_ptr<const Result> CountFailureTest::result() const
{
	return tests->result();
}
