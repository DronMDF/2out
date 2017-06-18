// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <Failure.h>

using namespace std;
using namespace oout;

string Failure::print(const Format &) const
{
	// @todo #109:15min Invoke Format From Failure::print
	return {};
}

Failure::operator bool() const
{
	return false;
}
