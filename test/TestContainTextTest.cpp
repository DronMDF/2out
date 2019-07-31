// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestContainTextTest.h"
#include <2out/2out.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

TestContainTextTest::TestContainTextTest()
	: tests(
		make_unique<TestNamed>(
			"TestContainTextTest",
			make_shared<const TestNamed>(
				"Contain all",
				make_shared<EqualTest>(
					make_unique<ReprTest>(
						make_unique<TestContainText>(
							"quick brown fox",
							"quick",
							"fox"
						)
					),
					"success"
				)
			),
			make_shared<const TestNamed>(
				"Not contain one of",
				make_shared<EqualTest>(
					make_unique<ReprTest>(
						make_unique<TestContainText>(
							"jumps over the lazy dog",
							"dog",
							"fox"
						)
					),
					"failure"
				)
			)
		)
	)
{
}

unique_ptr<const Result> TestContainTextTest::result() const
{
	return tests->result();
}
