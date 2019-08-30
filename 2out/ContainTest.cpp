// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ContainTest.h"
#include "MatchTest.h"
#include "Result.h"

using namespace std;
using namespace oout;

ContainTest::ContainTest(
	const shared_ptr<const Text> &text,
	const shared_ptr<const Match> &match
) : test(make_shared<MatchTest>(text, match))
{
}

unique_ptr<const Result> ContainTest::result() const
{
	return test->result();
}
