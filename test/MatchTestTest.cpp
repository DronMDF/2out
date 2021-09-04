// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MatchTestTest.h"
#include <2out/2out.h>
#include "TestText.h"

using namespace std;
using namespace oout;

MatchTestTest::MatchTestTest()
: dirty::Test(
	make_unique<NamedTest>(
		"MatchTest test",
		make_shared<const NamedTest>(
			"MatchTest success with success equal matcher",
			make_shared<EqualTest>(
				make_unique<TestText>(
					make_unique<MatchTest>(
						make_shared<StringText>("test"),
						make_shared<EqualMatch>("test")
					)
				),
				"success"
			)
		),
		make_shared<const NamedTest>(
			"MatchTest success with all success matcher",
			make_shared<EqualTest>(
				make_unique<TestText>(
					make_unique<MatchTest>(
						make_shared<StringText>("test"),
						make_shared<ContainMatch>("te"),
						make_shared<ContainMatch>("st")
					)
				),
				"success"
			)
		)
	)
)
{
}
