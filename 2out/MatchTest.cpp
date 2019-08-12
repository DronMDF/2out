// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MatchTest.h"
#include "Match.h"
#include "Result.h"

using namespace std;
using namespace oout;

MatchTest::MatchTest(
	const shared_ptr<const Text> &text,
	const shared_ptr<const Match> &match
) : text(text), match(match)
{
}

unique_ptr<const Result> MatchTest::result() const
{
	return match->match(text);
}
