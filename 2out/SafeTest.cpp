// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SafeTest.h"
#include "Error.h"
#include "TestResult.h"

using namespace std;
using namespace oout;

SafeTest::SafeTest(const shared_ptr<const Test> &test)
	: test(test)
{
}

unique_ptr<const Result> SafeTest::result() const
{
	unique_ptr<const Result> r;
	try {
		r = test->result();
	} catch (const exception &e) {
		r = make_unique<const TestResult>(make_shared<Error>(e.what()));
	}
	return r;
}
