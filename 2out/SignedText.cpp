// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "SignedText.h"

using namespace std;
using namespace oout;

SignedText::SignedText(int64_t value)
	: value(value)
{
}

string SignedText::asString() const
{
	return to_string(value);
}
