// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestNamed.h"
#include "ResNamed.h"
#include "TestSuite.h"

using namespace std;
using namespace oout;

TestNamed::TestNamed(const string &name, const list<shared_ptr<const Test>> &tests)
	: TestNamed(name, make_shared<TestSuite>(tests))
{
}

TestNamed::TestNamed(const string &name, const shared_ptr<const Test> &test)
	: name(name), test(test)
{
}

shared_ptr<const Result> TestNamed::result() const
{
	return make_shared<ResNamed>(test->result(), name);
}
