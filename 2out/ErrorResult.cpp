// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ErrorResult.h"
#include "Format.h"

using namespace std;
using namespace oout;

ErrorResult::ErrorResult(const string &text)
	: text(text)
{
}

string ErrorResult::print(const Format &format) const
{
	return format.error(text);
}
