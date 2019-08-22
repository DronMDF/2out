// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "AllMatch.h"
#include <list>
#include "SuiteResult.h"

using namespace std;
using namespace oout;

AllMatch::AllMatch(const vector<shared_ptr<const Match>> &matches)
	: matches(matches)
{
}

unique_ptr<const Result> AllMatch::match(const shared_ptr<const Text> &in) const
{
	// @todo #398 Need to introduce AllResult for accumulate multiple match result
	//  This is not Suite... This one test. Question about visualisation.
	list<shared_ptr<const Result>> results;
	for (const auto &m : matches) {
		results.push_back(m->match(in));
	}
	return make_unique<SuiteResult>(results);
}
