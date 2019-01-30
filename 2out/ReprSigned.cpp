// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprSigned.h"

using namespace std;
using namespace oout;

ReprSigned::ReprSigned(int64_t value)
	: value(value)
{
}

string ReprSigned::asString() const
{
	return to_string(value);
}
