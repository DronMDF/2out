// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ContainTest.h"
#include <algorithm>
#include <sstream>
#include "CondResult.h"
#include "ResSuite.h"
#include "ResTest.h"

using namespace std;
using namespace oout;

ContainTest::ContainTest(
	const shared_ptr<const Representation> &text,
	const list<shared_ptr<const Representation>> &subs
) : text(text), subs(subs)
{
}

unique_ptr<const Result> ContainTest::result() const
{
	if (subs.size() == 1) {
		return result(subs.front());
	}

	list<shared_ptr<const Result>> rs;
	for (const auto &s : subs) {
		rs.push_back(result(s));
	}
	return make_unique<ResSuite>(rs);
}

unique_ptr<const Result> ContainTest::result(const shared_ptr<const Representation> &sub) const
{
	// @todo #313 ContainTest invoke text->asString twice
	ostringstream test_text;
	test_text << "'" << sub->asString() << "' in '" << text->asString() << "'";

	return make_unique<const ResTest>(
		make_shared<CondResult>(
			text->asString().find(sub->asString()) != string::npos,
			test_text.str()
		)
	);
}
