// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CountErrorTest.h"
#include <2out/2out.h>
#include <2out/ResSuite.h>
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
		make_unique<NamedTest>(
			"CountErrorTest",
			make_shared<const NamedTest>(
				"One error in set",
				make_shared<EqualTest>(
					make_unique<CountErrorRepr>(
						make_unique<CountError>(
							make_unique<ResSuite>(
								make_shared<ResOkCase>(),
								make_shared<ResFailureCase>(),
								make_shared<ResErrorCase>()
							)
						)
					),
					"1"
				)
			)
		)
	)
{
}

unique_ptr<const Result> CountErrorTest::result() const
{
	return tests->result();
}
