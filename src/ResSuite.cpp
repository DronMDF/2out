// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <ResSuite.h>
#include <numeric>

using namespace std;
using namespace oout;

ResSuite::ResSuite(const list<shared_ptr<const Result>> &results)
	: results(results)
{
}

size_t ResSuite::failures() const
{
	return accumulate(
		results.begin(),
		results.end(),
		0,
		[](size_t v, const auto &t){ return v + t->failures(); }
	);
}

