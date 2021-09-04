// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EndsWithTestTest.h"
#include <2out/2out.h>
#include "TestText.h"

using namespace std;
using namespace oout;

EndsWithTestTest::EndsWithTestTest()
: dirty::Test(
	make_unique<NamedTest>(
		"EndsWithTest test",
		make_shared<const NamedTest>(
			"Realy ends with",
			make_shared<EqualTest>(
				make_unique<TestText>(
					make_unique<EndsWithTest>(
						"128aafc5ceb385649c1054fc5000",
						"000"
					)
				),
				"success"
			)
		),
		make_shared<const NamedTest>(
			"Ends with duplicates",
			make_shared<EqualTest>(
				make_unique<TestText>(
					make_unique<EndsWithTest>(
						"toctoc",
						"toc"
					)
				),
				"success"
			)
		),
		make_shared<const NamedTest>(
			"Not ends with",
			make_shared<EqualTest>(
				make_unique<TestText>(
					make_unique<EndsWithTest>(
						make_shared<SignedText>(123456789),
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
