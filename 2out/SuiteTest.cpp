// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SuiteTest.h"
#include "ResSuite.h"
#include "TimedTest.h"

using namespace std;
using namespace oout;

SuiteTest::SuiteTest(const list<shared_ptr<const Test>> &cases)
	: cases(cases)
{
}

unique_ptr<const Result> SuiteTest::result() const
{
	list<shared_ptr<const Result>> results;
	for (const auto &c : cases) {
		results.push_back(TimedTest(c).result());
	}
	return make_unique<ResSuite>(results);
}
