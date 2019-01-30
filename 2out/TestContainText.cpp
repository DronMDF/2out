// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestContainText.h"
#include <algorithm>
#include <sstream>
#include "Failure.h"
#include "ResSuite.h"
#include "ResTest.h"
#include "Success.h"

using namespace std;
using namespace oout;

TestContainText::TestContainText(
	const shared_ptr<const Representation> &text,
	const list<shared_ptr<const Representation>> &subs
) : text(text), subs(subs)
{
}

unique_ptr<const Result> TestContainText::result() const
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

unique_ptr<const Result> TestContainText::result(const shared_ptr<const Representation> &sub) const
{
	ostringstream test_text;
	test_text << "'" << sub->asString() << "' in '" << text->asString() << "'";

	// @todo #295 Result with condition halp to avoid if/else
	shared_ptr<const Result> assertion_result;
	if (text->asString().find(sub->asString()) != string::npos) {
		assertion_result = make_shared<Success>(test_text.str());
	} else {
		assertion_result = make_shared<Failure>(test_text.str());
	}
	return make_unique<const ResTest>(assertion_result);
}
