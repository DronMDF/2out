// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ContainMatch.h"
#include <sstream>
#include "Failure.h"
#include "Text.h"
#include "ResTest.h"
#include "Success.h"

using namespace std;
using namespace oout;

ContainMatch::ContainMatch(const string &text)
	: text(text)
{
}

// @todo #352 ContainMatch use deprecated Success/Failure
//  need to use CondResult instead
unique_ptr<const Result> ContainMatch::match(const shared_ptr<const Text> &in) const
{
	ostringstream message;
	message << "'" << text << "' in '" << in->asString() << "'";

	shared_ptr<const Result> assertion_result;
	if (in->asString().find(text) != string::npos) {
		assertion_result = make_shared<Success>(message.str());
	} else {
		assertion_result = make_shared<Failure>(message.str());
	}
	return make_unique<ResTest>(assertion_result);
}
