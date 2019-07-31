// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestNamedTest.h"
#include <2out/2out.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

class ReprTestNamed final : public Representation {
public:
	explicit ReprTestNamed(const shared_ptr<const Test> &test)
		: test(test)
	{
	}

	string asString() const override
	{
		return JUnitXmlReport(test->result()).asString();
	}
private:
	const shared_ptr<const Test> test;
};

TestNamedTest::TestNamedTest()
	: tests(
		make_unique<TestNamed>(
			"TestNamedTest",
			make_shared<const TestNamed>(
				"TestNamed in TestNamed is a Suite",
				make_shared<TestContainText>(
					make_shared<ReprTestNamed>(
						make_unique<TestNamed>(
							"Root test",
							make_shared<const TestNamed>(
								"Concrete test",
								make_shared<EqualTest>("a", "a")
							)
						)
					),
					"Concrete test"
				)
			)
		)
	)
{
}

unique_ptr<const Result> TestNamedTest::result() const
{
	return tests->result();
}
