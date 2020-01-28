// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ContainMatchTest.h"
#include <2out/2out.h>
#include "TestText.h"

using namespace std;
using namespace oout;

ContainMatchTest::ContainMatchTest()
: dirty::Test(
	make_unique<NamedTest>(
		"ContainMatch test",
		make_shared<const NamedTest>(
			"ContainMatch succes if contain",
			make_shared<EqualTest>(
				make_unique<TestText>(
					make_unique<MatchTest>(
						make_shared<StringText>("test"),
						make_shared<ContainMatch>("es")
					)
				),
				"success"
			)
		),
		make_shared<const NamedTest>(
			"ContainMatch failure if not contain",
			make_shared<EqualTest>(
				make_unique<TestText>(
					make_unique<MatchTest>(
						make_shared<StringText>("test"),
						make_shared<ContainMatch>("foo")
					)
				),
				"failure"
			)
		)
	)
)
{
}
