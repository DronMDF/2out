// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "RegexTest.h"
#include "MatchTest.h"
#include "RegexMatch.h"
#include "Result.h"
#include "StringText.h"

using namespace std;
using namespace oout;

RegexTest::RegexTest(const shared_ptr<const Text> &text, const string &re)
	: test(make_shared<MatchTest>(text, make_shared<RegexMatch>(re)))
{
}

RegexTest::RegexTest(const string &text, const string &re)
	: RegexTest(make_shared<StringText>(text), re)
{
}

unique_ptr<const Result> RegexTest::result() const
{
	return test->result();
}
