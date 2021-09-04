// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CountTestTest.h"
#include <2out/2out.h>
#include <2out/SuccessResult.h>
#include <2out/SuiteResult.h>
#include <2out/TestResult.h>

using namespace std;
using namespace oout;

class CountTestText final : public Text {
public:
	explicit CountTestText(const shared_ptr<const CountTest> &count)
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
	make_unique<NamedTest>(
		"CountTestTest",
		make_shared<EqualTest>(
			make_shared<CountTestText>(
				make_unique<CountTest>(
					make_unique<SuiteResult>(
						make_shared<TestResult>(
							make_shared<SuccessResult>()
						),
						make_shared<TestResult>(
							make_shared<SuccessResult>()
						),
						make_shared<TestResult>(
							make_shared<SuccessResult>()
						)
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
