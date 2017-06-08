// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TstTimed.h>
#include <ResTimed.h>

using namespace std;
using namespace oout;

TstTimed::TstTimed(const shared_ptr<const Test> &test)
	: test(test)
{
}

shared_ptr<const Result> TstTimed::result() const
{
	// @todo #94:15min Meansure execution time and pass into ResTimed
	return make_shared<const ResTimed>(
		test->result(),
		0
	);
}
