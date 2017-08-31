// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CountTestTest.h"
#include <2out/CountTest.h>
#include <2out/Representation.h>
#include <2out/ReprSigned.h>
#include <2out/ResSuite.h>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>
#include <2out/TestSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

class CountTestRepr final : public Representation {
public:
	explicit CountTestRepr(const shared_ptr<const CountTest> &count)
		: count(count)
	{
	}

	string asString() const override
	{
		return to_string(count->count());
	}
private:
	const shared_ptr<const CountTest> count;
};

CountTestTest::CountTestTest()
	: tests(
		make_unique<TestNamed>(
			"CountTestTest",
			make_shared<TestEqual>(
				make_shared<CountTestRepr>(
					make_unique<CountTest>(
						make_unique<ResSuite>(
							make_shared<ResOkCase>(),
							make_shared<ResOkCase>(),
							make_shared<ResOkCase>()
						)
					)
				),
				"3"
			)
		)
	)
{
}

unique_ptr<const Result> CountTestTest::result() const
{
	return tests->result();
}
