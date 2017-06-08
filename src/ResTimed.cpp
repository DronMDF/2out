// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <ResTimed.h>
#include <Format.h>

using namespace std;
using namespace oout;

ResTimed::ResTimed(const shared_ptr<const Result> &result, float time)
	: result(result), time(time)
{
}

string ResTimed::print(const Format &format) const
{
	// @todo #94:15min Implement Timed Format whoes bind time inside
	return result->print(format);
}
