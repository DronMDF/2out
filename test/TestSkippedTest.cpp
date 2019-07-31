// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestSkippedTest.h"
#include <2out/2out.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

TestSkippedTest::TestSkippedTest()
	: tests(
		make_unique<TestNamed>(
			"TestSkippedTest",
			make_shared<const TestNamed>(
				"Skipped test looks like Success",
				make_shared<EqualTest>(
					make_unique<ReprTest>(
						make_unique<TestSkipped>(
							make_unique<EqualTest>(
								"true",
								"false"
							)
						)
					),
					"success"
				)
			)
		)
	)
{
}

unique_ptr<const Result> TestSkippedTest::result() const
{
	return tests->result();
}

