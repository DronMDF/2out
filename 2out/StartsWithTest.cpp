// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StartsWithTest.h"
#include "MatchTest.h"
#include "StringText.h"
#include "Result.h"
#include "StartsWithMatch.h"

using namespace std;
using namespace oout;

StartsWithTest::StartsWithTest(const shared_ptr<const Text> &a, const string &b)
	: test(make_shared<MatchTest>(a, make_shared<StartsWithMatch>(b)))
{
}

StartsWithTest::StartsWithTest(const string &a, const string &b)
	: StartsWithTest(make_shared<StringText>(a), b)
{
}

unique_ptr<const Result> StartsWithTest::result() const
{
	return test->result();
}
