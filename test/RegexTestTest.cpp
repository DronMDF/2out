// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "RegexTestTest.h"
#include <2out/2out.h>
#include "TestText.h"

using namespace std;
using namespace oout;

RegexTestTest::RegexTestTest()
: dirty::Test(
	make_shared<NamedTest>(
		"RegexTest test",
		make_shared<NamedTest>(
			"RegexTest success if matched",
			make_shared<EqualTest>(
				make_unique<TestText>(
					make_unique<RegexTest>(
						make_shared<StringText>("test"),
						"t.+t"
					)
				),
				"success"
			)
		),
		make_shared<NamedTest>(
			"RegexTest failure if not match",
			make_shared<EqualTest>(
				make_unique<TestText>(
					make_unique<RegexTest>(
						make_shared<StringText>("test"),
						R"(\d+)"
					)
				),
				"failure"
			)
		)
	)
)
{
}
