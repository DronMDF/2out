// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SuiteTest.h"
#include "SafeTest.h"
#include "SuiteResult.h"
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
		results.push_back(TimedTest(make_shared<SafeTest>(c)).result());
	}
	return make_unique<SuiteResult>(results);
}
