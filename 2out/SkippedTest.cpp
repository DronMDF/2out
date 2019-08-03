// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SkippedTest.h"
#include "ResTest.h"
#include "Success.h"

using namespace std;
using namespace oout;

SkippedTest::SkippedTest(const shared_ptr<const Test> &test)
	: test(test)
{
}

unique_ptr<const Result> SkippedTest::result() const
{
	return make_unique<ResTest>(make_unique<Success>());
}
