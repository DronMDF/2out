// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestResult.h"
#include "Format.h"

using namespace std;
using namespace oout;

TestResult::TestResult(const shared_ptr<const Result> &result)
	: result(result)
{
}

string TestResult::print(const Format &format) const
{
	return format.test({}, result, chrono::nanoseconds::zero());
}
