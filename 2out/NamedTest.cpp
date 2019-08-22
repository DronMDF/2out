// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "NamedTest.h"
#include "NamedResult.h"
#include "SuiteTest.h"

using namespace std;
using namespace oout;

NamedTest::NamedTest(const string &name, const shared_ptr<const Test> &test)
	: name(name), test(test)
{
}

NamedTest::NamedTest(const string &name, const shared_ptr<const NamedTest> &test)
	: NamedTest(name, make_shared<const SuiteTest>(test))
{
}

NamedTest::NamedTest(const string &name, const list<shared_ptr<const Test>> &tests)
	: NamedTest(name, make_shared<const SuiteTest>(tests))
{
}

unique_ptr<const Result> NamedTest::result() const
{
	return make_unique<NamedResult>(name, test->result());
}
