// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "RegexMatch.h"
#include <sstream>
#include <regex>
#include "Text.h"
#include "TestResult.h"
#include "CondResult.h"

using namespace std;
using namespace oout;

RegexMatch::RegexMatch(const string &re)
	: re(re)
{
}

unique_ptr<const Result> RegexMatch::match(const shared_ptr<const Text> &in) const
{
	const auto origin = in->asString();
	ostringstream message;
	message << "'" << origin << "' match with '" << re << "'";

	return make_unique<TestResult>(
		make_shared<CondResult>(regex_search(origin, regex(re)), message.str())
	);
}
