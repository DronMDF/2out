// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <ResSuite.h>
#include <numeric>
#include <Format.h>

using namespace std;
using namespace oout;

ResSuite::ResSuite(const list<shared_ptr<const Result>> &results)
	: results(results)
{
}

string ResSuite::print(const Format &format) const
{
	return format.suite({}, 0, results);
}
