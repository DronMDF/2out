// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ResTest.h"
#include "Format.h"

using namespace std;
using namespace oout;

ResTest::ResTest(const shared_ptr<const Result> &result)
	: result(result)
{
}

string ResTest::print(const Format &format) const
{
	return format.test({}, result, chrono::nanoseconds::zero());
}
