// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "StringText.h"

using namespace std;
using namespace oout;

StringText::StringText(const string &value)
	: value(value)
{
}

string StringText::asString() const
{
	return value;
}
