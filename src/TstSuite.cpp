// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TstSuite.h>
#include <ResSimple.h>

using namespace std;
using namespace oout;

TstSuite::TstSuite(const string &description, const list<shared_ptr<const Test>> &cases)
	: cases(cases)
{
}

shared_ptr<const Result> TstSuite::result() const
{
	// @todo #28:15min Need ResSuite for keep all sub tests results
	for (const auto &c : cases) {
		if (!c->result()) {
			return make_shared<ResSimple>(false);
		}
	}
	return make_shared<ResSimple>(true);
}
