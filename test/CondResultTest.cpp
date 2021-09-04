// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CondResultTest.h"
#include <2out/2out.h>
#include <2out/CondResult.h>
#include "CountFailureRepr.h"

using namespace std;
using namespace oout;

CondResultTest::CondResultTest()
: dirty::Test(
	"CondResult test",
	make_shared<const NamedTest>(
		"CondResult succes if cond is true",
		make_shared<EqualTest>(
			make_shared<CountFailureRepr>(
				make_shared<CountFailure>(
					make_shared<CondResult>(true, "success")
				)
			),
			"0"
		)
	),
	make_shared<const NamedTest>(
		"CondResult failure if cond is false",
		make_shared<EqualTest>(
			make_shared<CountFailureRepr>(
				make_shared<CountFailure>(
					make_shared<CondResult>(false, "failure")
				)
			),
			"1"
		)
	)
)
{
}
