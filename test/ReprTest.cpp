// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprTest.h"
#include <2out/2out.h>

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
