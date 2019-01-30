// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestEndsWith.h"
#include <sstream>
#include "Failure.h"
#include "ReprString.h"
#include "ResTest.h"
#include "Success.h"

using namespace std;
using namespace oout;

TestEndsWith::TestEndsWith(const string &a, const string &b)
	: TestEndsWith(make_shared<ReprString>(a), make_shared<ReprString>(b))
{
}

TestEndsWith::TestEndsWith(const string &a, const shared_ptr<const Representation> &b)
	: TestEndsWith(make_shared<ReprString>(a), b)
{
}

TestEndsWith::TestEndsWith(const shared_ptr<const Representation> &a, const string &b)
	: TestEndsWith(a, make_shared<ReprString>(b))
{
}

TestEndsWith::TestEndsWith(
	const shared_ptr<const Representation> &a,
	const shared_ptr<const Representation> &b
) : a(a), b(b)
{
}

unique_ptr<const Result> TestEndsWith::result() const
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
