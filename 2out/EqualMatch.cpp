// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EqualMatch.h"
#include <sstream>
#include "CondResult.h"
#include "Text.h"
#include "TestResult.h"

using namespace std;
using namespace oout;

EqualMatch::EqualMatch(const string &text)
	: text(text)
{
}

unique_ptr<const Result> EqualMatch::match(const shared_ptr<const Text> &in) const
{
	const auto origin = in->asString();
	ostringstream message;
	message << "'" << origin << "' is equal '" << text << "'";
	return make_unique<TestResult>(
		make_shared<CondResult>(origin == text, message.str())
	);
}
