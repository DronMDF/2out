// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CondResult.h"
#include "Format.h"

using namespace std;
using namespace oout;

CondResult::CondResult(bool cond, const string &message)
	: cond(cond), message(message)
{
}

string CondResult::print(const Format &format) const
{
	if (cond) {
		return format.success(message);
	}
	return format.failure(message);
}
