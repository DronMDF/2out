// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestSkippedTest.h"
#include <2out/Result.h>
#include <2out/TestNamed.h>
#include <2out/TestEqual.h>
#include <2out/TestSkipped.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

TestSkippedTest::TestSkippedTest()
: tests(
	make_unique<TestNamed>(
		"TestSkippedTest",
		list<shared_ptr<const Test>>{
			make_unique<TestNamed>(
				"Skipped test looks like Success",
				make_unique<TestEqual>(
					make_unique<ReprTest>(
						make_unique<TestSkipped>(
							make_unique<TestEqual>(
								"true",
								"false"
							)
						)
					),
					"success"
				)
			)
		}
	)
)
{
}

unique_ptr<const Result> TestSkippedTest::result() const
{
	return tests->result();
}

