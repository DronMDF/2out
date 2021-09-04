// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ContainMatch.h"
#include <sstream>
#include "CondResult.h"
#include "TestResult.h"
#include "Text.h"

using namespace std;
using namespace oout;

ContainMatch::ContainMatch(const string &text)
	: text(text)
{
}

unique_ptr<const Result> ContainMatch::match(const shared_ptr<const Text> &in) const
{
	const auto origin = in->asString();
	ostringstream message;
	message << "'" << text << "' in '" << origin << "'";
	return make_unique<TestResult>(
		make_shared<CondResult>(origin.find(text) != string::npos, message.str())
	);
}
