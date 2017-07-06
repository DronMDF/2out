// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ResSimple.h"
#include "Format.h"

using namespace std;
using namespace oout;

ResSimple::ResSimple(const shared_ptr<const Result> &result)
	: result(result)
{
}

string ResSimple::print(const Format &format) const
{
	return format.test("", result, 0);
}
