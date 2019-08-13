// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EndsWithMatchTest.h"
#include <2out/2out.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

EndsWithMatchTest::EndsWithMatchTest()
: dirty::Test(
	make_unique<NamedTest>(
		"EndsWithMatch test",
		make_shared<const NamedTest>(
			"EndsWith success if ends with",
			make_shared<EqualTest>(
				make_unique<ReprTest>(
					make_unique<MatchTest>(
						make_shared<StringText>("test"),
						make_shared<EndsWithMatch>("est")
					)
				),
				"success"
			)
		),
		make_shared<const NamedTest>(
			"EndsWith success if pattern not at end",
			make_shared<EqualTest>(
				make_unique<ReprTest>(
					make_unique<MatchTest>(
						make_shared<StringText>("toptop"),
						make_shared<EndsWithMatch>("top")
					)
				),
				"success"
			)
		),
		make_shared<const NamedTest>(
			"EndsWithMatch failure if not ends with",
			make_shared<EqualTest>(
				make_unique<ReprTest>(
					make_unique<MatchTest>(
						make_shared<StringText>("test"),
						make_shared<EndsWithMatch>("tes")
					)
				),
				"failure"
			)
		)
	)
)
{
}
