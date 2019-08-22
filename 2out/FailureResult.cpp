// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FailureResult.h"
#include "Format.h"

using namespace std;
using namespace oout;

FailureResult::FailureResult(const string &text)
	: text(text)
{
}

string FailureResult::print(const Format &format) const
{
	return format.failure(text);
}
