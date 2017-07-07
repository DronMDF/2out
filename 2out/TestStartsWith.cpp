// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestStartsWith.h"
#include <sstream>
#include "Failure.h"
#include "ReprString.h"
#include "ResTest.h"
#include "Success.h"

using namespace std;
using namespace oout;

TestStartsWith::TestStartsWith(const string &a, const string &b)
	: TestStartsWith(make_shared<ReprString>(a), make_shared<ReprString>(b))
{
}

TestStartsWith::TestStartsWith(const string &a, const shared_ptr<const Representation> &b)
	: TestStartsWith(make_shared<ReprString>(a), b)
{
}

TestStartsWith::TestStartsWith(const shared_ptr<const Representation> &a, const string &b)
	: TestStartsWith(a, make_shared<ReprString>(b))
{
}

TestStartsWith::TestStartsWith(
	const shared_ptr<const Representation> &a,
	const shared_ptr<const Representation> &b
) : a(a), b(b)
{
}

shared_ptr<const Result> TestStartsWith::result() const
{
	ostringstream text;
	text << "'" << a->asString() << "' is starts with '" << b->asString() << "'";

	shared_ptr<const Result> assertion_result;
	if (a->asString().find(b->asString()) == 0) {
		assertion_result = make_shared<Success>(text.str());
	} else {
		assertion_result = make_shared<Failure>(text.str());
	}
	return make_shared<ResTest>(assertion_result);
}
