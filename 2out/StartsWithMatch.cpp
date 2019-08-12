// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StartsWithMatch.h"
#include <sstream>
#include "Text.h"
#include "ResTest.h"
#include "CondResult.h"

using namespace std;
using namespace oout;

StartsWithMatch::StartsWithMatch(const string &text)
	: text(text)
{
}

unique_ptr<const Result> StartsWithMatch::match(const shared_ptr<const Text> &in) const
{
	ostringstream message;
	message << "'" << in->asString() << "' starts with '" << text << "'";

	return make_unique<ResTest>(
		make_shared<CondResult>(
			in->asString().find(text) == 0,
			message.str()
		)
	);
}
