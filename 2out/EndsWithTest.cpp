// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EndsWithTest.h"
#include "EndsWithMatch.h"
#include "MatchTest.h"
#include "ReprString.h"
#include "Result.h"

using namespace std;
using namespace oout;

EndsWithTest::EndsWithTest(const shared_ptr<const Text> &a, const string &b)
	: test(make_shared<MatchTest>(a, make_shared<EndsWithMatch>(b)))
{
}

EndsWithTest::EndsWithTest(const string &a, const string &b)
	: EndsWithTest(make_shared<ReprString>(a), b)
{
}

unique_ptr<const Result> EndsWithTest::result() const
{
	return test->result();
}
