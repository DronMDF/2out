// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprTest.h"
#include <2out/CountFailure.h>

using namespace std;
using namespace oout;

ReprTest::ReprTest(const shared_ptr<const Test> &test)
	: test(test)
{
}

string ReprTest::asString() const
{
	return CountFailure(test->result()).count() == 0 ? "success" : "failure";
}
