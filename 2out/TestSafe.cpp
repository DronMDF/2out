// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestSafe.h"
#include "Error.h"
#include "ResSimple.h"

using namespace std;
using namespace oout;

TestSafe::TestSafe(const shared_ptr<const Test> &test)
	: test(test)
{
}

shared_ptr<const Result> TestSafe::result() const
{
	shared_ptr<const Result> r;
	try {
		r = test->result();
	} catch (const exception &e) {
		r = make_shared<const ResSimple>(make_shared<Error>(e.what()));
	}
	return r;
}
