// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestText.h"
#include <2out/2out.h>

using namespace std;
using namespace oout;

TestText::TestText(const shared_ptr<const Test> &test)
	: test(test)
{
}

string TestText::asString() const
{
	const shared_ptr<const Result> result = test->result();
	if (CountError(result).count() > 0) {
		return "error";
	}
	if (CountFailure(result).count() > 0) {
		return "failure";
	}
	return "success";
}
