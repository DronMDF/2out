// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EndsWithMatch.h"
#include <sstream>
#include "Representation.h"
#include "ResTest.h"
#include "CondResult.h"

using namespace std;
using namespace oout;

EndsWithMatch::EndsWithMatch(const string &text)
	: text(text)
{
}

unique_ptr<const Result> EndsWithMatch::match(const shared_ptr<const Representation> &in) const
{
	const auto origin = in->asString();
	ostringstream message;
	message << "'" << origin << "' ends with '" << text << "'";

	return make_unique<ResTest>(
		make_shared<CondResult>(
			string(origin, origin.size() - text.size()) == text,
			message.str()
		)
	);
}
