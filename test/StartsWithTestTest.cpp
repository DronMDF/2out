// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StartsWithTestTest.h"
#include <2out/2out.h>
#include "TestText.h"

using namespace std;
using namespace oout;

StartsWithTestTest::StartsWithTestTest()
	: tests(
		make_unique<NamedTest>(
			"StartsWithTestTest",
			make_shared<const NamedTest>(
				"Realy starts with",
				make_shared<EqualTest>(
					make_unique<TestText>(
						make_unique<StartsWithTest>(
							"abcdef",
							"abc"
						)
					),
					"success"
				)
			)
		)
	)
{
}

unique_ptr<const Result> StartsWithTestTest::result() const
{
	return tests->result();
}
