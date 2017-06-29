// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TestEqual.h>
#include <sstream>
#include <algorithm>
#include <AssertionResult.h>
#include <Failure.h>
#include <ReprString.h>
#include <ResSimple.h>
#include <Success.h>

using namespace std;
using namespace oout;

TestEqual::TestEqual(const string &a, const string &b)
	: TestEqual(make_shared<ReprString>(a), make_shared<ReprString>(b))
{
}

TestEqual::TestEqual(const string &a, const shared_ptr<const Representation> &b)
	: TestEqual(make_shared<ReprString>(a), b)
{
}

TestEqual::TestEqual(const shared_ptr<const Representation> &a, const string &b)
	: TestEqual(a, make_shared<ReprString>(b))
{
}

TestEqual::TestEqual(const shared_ptr<const Representation> &a, const shared_ptr<const Representation> &b)
	: a(a), b(b)
{
}

shared_ptr<const Result> TestEqual::result() const
{
	ostringstream text;
	text << "'" << a->asString() << "' is equal '" << b->asString() << "'";

	shared_ptr<const AssertionResult> assertion_result;
	if (a->asString() == b->asString()) {
		assertion_result = make_shared<Success>(text.str());
	} else {
		assertion_result = make_shared<Failure>(text.str());
	}
	return make_shared<ResSimple>("", assertion_result);
}
