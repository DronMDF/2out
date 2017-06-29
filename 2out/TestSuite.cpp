// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TestSuite.h>
#include <ResSuite.h>
#include <TestTimed.h>

using namespace std;
using namespace oout;

TestSuite::TestSuite(const list<shared_ptr<const Test>> &cases)
	: cases(cases)
{
}

shared_ptr<const Result> TestSuite::result() const
{
	list<shared_ptr<const Result>> results;
	for (const auto &c : cases) {
		results.push_back(TestTimed(c).result());
	}
	return make_shared<ResSuite>("", results);
}
