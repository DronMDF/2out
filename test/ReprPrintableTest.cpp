// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprPrintableTest.h"
#include <list>
#include <2out/ReprPrintable.h>
#include <2out/Result.h>
#include <2out/TestEqual.h>
#include <2out/TestNamed.h>

using namespace std;
using namespace oout;

ReprPrintableTest::ReprPrintableTest()
: tests(
	make_unique<TestNamed>(
		"ReprPrintableTest",
		list<shared_ptr<const Test>>{
			make_unique<TestNamed>(
				"Boolean represent as text",
				make_unique<TestEqual>(
					make_unique<ReprPrintable<bool>>(
						true
					),
					"true"
				)
			)
		}
	)
)
{
}

unique_ptr<const Result> ReprPrintableTest::result() const
{
	return tests->result();
}
