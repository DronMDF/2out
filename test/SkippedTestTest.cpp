// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SkippedTestTest.h"
#include <2out/2out.h>
#include "TestText.h"

using namespace std;
using namespace oout;

SkippedTestTest::SkippedTestTest()
	: tests(
		make_unique<NamedTest>(
			"SkippedTest test",
			make_shared<const NamedTest>(
				"Skipped test looks like Success",
				make_shared<EqualTest>(
					make_unique<TestText>(
						make_unique<SkippedTest>(
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

unique_ptr<const Result> SkippedTestTest::result() const
{
	return tests->result();
}
