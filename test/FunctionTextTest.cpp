// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FunctionTextTest.h"
#include <2out/2out.h>

using namespace std;
using namespace oout;

FunctionTextTest::FunctionTextTest()
	: tests(
		make_unique<NamedTest>(
			"FunctionTextTest",
			make_shared<const NamedTest>(
				"implicit bind",
				make_shared<EqualTest>(
					make_shared<FunctionText>([]{ return "777"; }),
					"777"
				)
			)
		)
	)
{
}

unique_ptr<const Result> FunctionTextTest::result() const
{
	return tests->result();
}
