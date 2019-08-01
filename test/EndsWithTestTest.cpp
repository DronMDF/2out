// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EndsWithTestTest.h"
#include <2out/2out.h>
#include "ReprTest.h"

using namespace std;
using namespace oout;

EndsWithTestTest::EndsWithTestTest()
	: tests(
		make_unique<TestNamed>(
			"EndsWithTestTest",
			make_shared<const TestNamed>(
				"Realy ends with",
				make_shared<EqualTest>(
					make_unique<ReprTest>(
						make_unique<EndsWithTest>(
							"128aafc5ceb385649c1054fc5000",
							"000"
						)
					),
					"success"
				)
			),
			make_shared<const TestNamed>(
				"Not ends with",
				make_shared<EqualTest>(
					make_unique<ReprTest>(
						make_unique<EndsWithTest>(
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

unique_ptr<const Result> EndsWithTestTest::result() const
{
	return tests->result();
}
