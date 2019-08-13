// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EqualTest.h"
#include "EqualMatch.h"
#include "MatchTest.h"
#include "StringText.h"
#include "Result.h"

using namespace std;
using namespace oout;

EqualTest::EqualTest(const shared_ptr<const Text> &a, const string &b)
	: test(make_shared<MatchTest>(a, make_shared<EqualMatch>(b)))
{
}

EqualTest::EqualTest(const string &a, const string &b)
	: EqualTest(make_shared<StringText>(a), b)
{
}

unique_ptr<const Result> EqualTest::result() const
{
	return test->result();
}
