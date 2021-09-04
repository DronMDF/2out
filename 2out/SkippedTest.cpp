// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SkippedTest.h"
#include "TestResult.h"
#include "SuccessResult.h"

using namespace std;
using namespace oout;

SkippedTest::SkippedTest(const shared_ptr<const Test> &test)
	: test(test)
{
}

unique_ptr<const Result> SkippedTest::result() const
{
	return make_unique<TestResult>(make_unique<SuccessResult>());
}
