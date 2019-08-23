// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "PrintableTextTest.h"
#include <list>
#include <2out/2out.h>

using namespace std;
using namespace oout;

PrintableTextTest::PrintableTextTest()
	: tests(
		make_unique<NamedTest>(
			"PrintableTextTest",
			make_shared<const NamedTest>(
				"Boolean represent as text",
				make_shared<EqualTest>(
					make_unique<PrintableText<bool>>(
						true
					),
					"true"
				)
			)
		)
	)
{
}

unique_ptr<const Result> PrintableTextTest::result() const
{
	return tests->result();
}
