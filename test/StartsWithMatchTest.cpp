// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StartsWithMatchTest.h"
#include <2out/2out.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

StartsWithMatchTest::StartsWithMatchTest()
: dirty::Test(
	make_unique<NamedTest>(
		"StartsWithMatch test",
		make_shared<const NamedTest>(
			"StartsWith success if starts with",
			make_shared<EqualTest>(
				make_unique<ReprTest>(
					make_unique<MatchTest>(
						make_shared<StringText>("test"),
						make_shared<StartsWithMatch>("tes")
					)
				),
				"success"
			)
		),
		make_shared<const NamedTest>(
			"StartsWithMatch failure if not starts with",
			make_shared<EqualTest>(
				make_unique<ReprTest>(
					make_unique<MatchTest>(
						make_shared<StringText>("test"),
						make_shared<StartsWithMatch>("est")
					)
				),
				"failure"
			)
		)
	)
)
{
}
