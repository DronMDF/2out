// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <Success.h>

using namespace std;
using namespace oout;

string Success::print(const Format &) const
{
	// @todo #109:15min Invoke Format From Success::print
	return {};
}

Success::operator bool() const
{
	return true;
}
