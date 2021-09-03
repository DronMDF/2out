// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SafeTestTest.h"
#include <2out/2out.h>
#include "TestText.h"

using namespace std;
using namespace oout;

SafeTestTest::SafeTestTest()
: dirty::Test(
	make_shared<NamedTest>(
		"SafeTest test",
		make_shared<const NamedTest>(
			"SafeTest produce error if exceprion are throw",
			make_shared<TestText>(
				make_shared<SafeTest>(
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
)
{
}
