// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StartsWithTest.h"
#include <sstream>
#include "Failure.h"
#include "ReprString.h"
#include "ResTest.h"
#include "Success.h"

using namespace std;
using namespace oout;

StartsWithTest::StartsWithTest(const string &a, const string &b)
	: StartsWithTest(make_shared<ReprString>(a), make_shared<ReprString>(b))
{
}

StartsWithTest::StartsWithTest(const string &a, const shared_ptr<const Text> &b)
	: StartsWithTest(make_shared<ReprString>(a), b)
{
}

StartsWithTest::StartsWithTest(const shared_ptr<const Text> &a, const string &b)
	: StartsWithTest(a, make_shared<ReprString>(b))
{
}

StartsWithTest::StartsWithTest(
	const shared_ptr<const Text> &a,
	const shared_ptr<const Text> &b
) : a(a), b(b)
{
}

unique_ptr<const Result> StartsWithTest::result() const
{
	ostringstream text;
	text << "'" << a->asString() << "' is starts with '" << b->asString() << "'";

	shared_ptr<const Result> assertion_result;
	if (a->asString().find(b->asString()) == 0) {
		assertion_result = make_shared<Success>(text.str());
	} else {
		assertion_result = make_shared<Failure>(text.str());
	}
	return make_unique<ResTest>(assertion_result);
}
