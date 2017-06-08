// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TstSuite.h>
#include <ResSuite.h>
#include <TstTimed.h>

using namespace std;
using namespace oout;

TstSuite::TstSuite(const string &description, const list<shared_ptr<const Test>> &cases)
	: description(description), cases(cases)
{
}

shared_ptr<const Result> TstSuite::result() const
{
	list<shared_ptr<const Result>> results;
	for (const auto &c : cases) {
		results.push_back(TstTimed(c).result());
	}
	return make_shared<ResSuite>(description, 0, results);
}
