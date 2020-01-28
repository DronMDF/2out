// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Test.h"
#include "../Result.h"

using namespace std;
using namespace oout;

dirty::Test::Test(const shared_ptr<const oout::Test> &tests)
	: tests(tests)
{
}

unique_ptr<const Result> dirty::Test::result() const
{
	return tests->result();
}
