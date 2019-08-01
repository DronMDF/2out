// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EndsWithTest.h"
#include <sstream>
#include "Failure.h"
#include "ReprString.h"
#include "ResTest.h"
#include "Success.h"

using namespace std;
using namespace oout;

EndsWithTest::EndsWithTest(const string &a, const string &b)
	: EndsWithTest(make_shared<ReprString>(a), make_shared<ReprString>(b))
{
}

EndsWithTest::EndsWithTest(const string &a, const shared_ptr<const Representation> &b)
	: EndsWithTest(make_shared<ReprString>(a), b)
{
}

EndsWithTest::EndsWithTest(const shared_ptr<const Representation> &a, const string &b)
	: EndsWithTest(a, make_shared<ReprString>(b))
{
}

EndsWithTest::EndsWithTest(
	const shared_ptr<const Representation> &a,
	const shared_ptr<const Representation> &b
) : a(a), b(b)
{
}

unique_ptr<const Result> EndsWithTest::result() const
{
	ostringstream text;
	text << "'" << a->asString() << "' is ends with '" << b->asString() << "'";

	shared_ptr<const Result> assertion_result;
	const auto as = a->asString();
	const auto bs = b->asString();
	if (as.rfind(bs) == as.size() - bs.size()) {
		assertion_result = make_shared<Success>(text.str());
	} else {
		assertion_result = make_shared<Failure>(text.str());
	}
	return make_unique<ResTest>(assertion_result);
}
