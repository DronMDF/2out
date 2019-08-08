// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "RegexMatchTest.h"
#include <2out/2out.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

RegexMatchTest::RegexMatchTest()
: dirty::Test(
	make_shared<NamedTest>(
		"RegexMatch test",
		make_shared<NamedTest>(
			"RegexMatch success if matched",
			make_shared<EqualTest>(
				make_unique<ReprTest>(
					make_unique<MatchTest>(
						make_shared<ReprString>("test"),
						make_shared<RegexMatch>("^te"),
						make_shared<RegexMatch>("st$"),
						make_shared<RegexMatch>("[tes]{4}")
					)
				),
				"success"
			)
		),
		make_shared<NamedTest>(
			"RegexMatch failure if not match",
			make_shared<EqualTest>(
				make_unique<ReprTest>(
					make_unique<MatchTest>(
						make_shared<ReprString>("test"),
						make_shared<RegexMatch>(R"(\d+)")
					)
				),
				"failure"
			)
		)
	)
)
{
}
