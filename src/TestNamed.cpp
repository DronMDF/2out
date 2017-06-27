// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TestNamed.h>

using namespace std;
using namespace oout;

TestNamed::TestNamed(const string &name, const shared_ptr<const Test> &test)
	: name(name), test(test)
{
}

shared_ptr<const Result> TestNamed::result() const
{
	// @todo #191:15min Need introduce ResNamed, Result whoes add name to test, or suite.
	return test->result();
}
