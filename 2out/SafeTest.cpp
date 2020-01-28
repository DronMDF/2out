// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SafeTest.h"
#include "ErrorResult.h"
#include "TestResult.h"

using namespace std;
using namespace oout;

SafeTest::SafeTest(const shared_ptr<const Test> &test)
	: test(test)
{
}

unique_ptr<const Result> SafeTest::result() const
{
	try {
		return test->result();
	} catch (const exception &e) {
		return make_unique<const TestResult>(make_shared<ErrorResult>(e.what()));
	}
}
