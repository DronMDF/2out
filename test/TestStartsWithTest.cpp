// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestStartsWithTest.h"
#include <2out/2out.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

TestStartsWithTest::TestStartsWithTest()
	: tests(
		make_unique<TestNamed>(
			"TestStartsWithTest",
			make_shared<const TestNamed>(
				"Realy starts with",
				make_shared<TestEqual>(
					make_unique<ReprTest>(
						make_unique<TestStartsWith>(
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

unique_ptr<const Result> TestStartsWithTest::result() const
{
	return tests->result();
}
