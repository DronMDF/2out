// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SuiteResult.h"
#include "Format.h"

using namespace std;
using namespace oout;

SuiteResult::SuiteResult(const list<shared_ptr<const Result>> &results)
	: results(results)
{
}

string SuiteResult::print(const Format &format) const
{
	return format.suite({}, chrono::nanoseconds::zero(), results);
}
