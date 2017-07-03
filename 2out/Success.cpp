// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Success.h"
#include "Format.h"

using namespace std;
using namespace oout;

Success::Success(const string &text)
	: text(text)
{
}

string Success::print(const Format &format) const
{
	return format.success(text);
}
