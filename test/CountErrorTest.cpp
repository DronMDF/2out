// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CountErrorTest.h"
#include <2out/2out.h>
#include <2out/ErrorResult.h>
#include <2out/FailureResult.h>
#include <2out/SuccessResult.h>
#include <2out/SuiteResult.h>

using namespace std;
using namespace oout;

class CountErrorText final : public Text {
public:
	explicit CountErrorText(const shared_ptr<const CountError> &count)
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
		"CountError test",
		make_shared<const NamedTest>(
			"One error in set",
			make_shared<EqualTest>(
				make_unique<CountErrorText>(
					make_unique<CountError>(
						make_unique<SuiteResult>(
							make_shared<SuccessResult>(),
							make_shared<FailureResult>(),
							make_shared<ErrorResult>()
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
