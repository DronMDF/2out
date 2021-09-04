// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SuiteTestTest.h"
#include <2out/2out.h>
#include "TestText.h"

using namespace std;
using namespace oout;

SuiteTestTest::SuiteTestTest()
: dirty::Test(
	"SuiteTestTest",
	make_shared<NamedTest>(
		"SuiteTest with empty list is always success",
		make_shared<EqualTest>(
			make_shared<TestText>(
				make_unique<SuiteTest>(
					list<shared_ptr<const oout::Test>>{}
				)
			),
			"success"
		)
	),
	make_shared<NamedTest>(
		"SuiteTest give tests as variadic args",
		make_shared<EqualTest>(
			make_shared<TestText>(
				make_unique<SuiteTest>(
					make_shared<EqualTest>("1", "1"),
					make_shared<EqualTest>("2", "2"),
					make_shared<EqualTest>("3", "3")
				)
			),
			"success"
		)
	),
	make_shared<NamedTest>(
		"SuiteTest run each test in SafeTest decorator",
		make_shared<TestText>(
			make_unique<SuiteTest>(
				make_shared<MatchTest>(
					make_shared<FunctionText>(
						[]() -> string {
							throw runtime_error("Shit");
						}
					),
					make_shared<EqualMatch>("Good")  // Not happen
				)
			)
		),
		make_shared<EqualMatch>("error")
	)
)
{
}
