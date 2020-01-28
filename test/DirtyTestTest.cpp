// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "DirtyTestTest.h"
#include <2out/2out.h>

using namespace std;
using namespace oout;

// This class inherit from dirty::Test, and test it by compiler
DirtyTestTest::DirtyTestTest()
	: dirty::Test(
		make_shared<ContainTest>(
			"oout::dirty::Test",
			"Test"
		),
		make_shared<StartsWithTest>(
			"oout::dirty::Test",
			"oout::dirty"
		)
	)
{
}
