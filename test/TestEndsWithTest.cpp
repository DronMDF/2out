// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestEndsWithTest.h"
#include <2out/2out.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

TestEndsWithTest::TestEndsWithTest()
	: tests(
		make_unique<TestNamed>(
			"TestEndsWithTest",
			make_shared<const TestNamed>(
				"Realy ends with",
				make_shared<TestEqual>(
					make_unique<ReprTest>(
						make_unique<TestEndsWith>(
							"128aafc5ceb385649c1054fc5000",
							"000"
						)
					),
					"success"
				)
			),
			make_shared<const TestNamed>(
				"Not ends with",
				make_shared<TestEqual>(
					make_unique<ReprTest>(
						make_unique<TestEndsWith>(
							make_shared<ReprSigned>(123456789),
							"000"
						)
					),
					"failure"
				)
			)
		)
	)
{
}

unique_ptr<const Result> TestEndsWithTest::result() const
{
	return tests->result();
}
