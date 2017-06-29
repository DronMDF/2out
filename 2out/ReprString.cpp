// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <ReprString.h>

using namespace std;
using namespace oout;

ReprString::ReprString(const string &value)
	: value(value)
{
}

string ReprString::asString() const
{
	return value;
}
