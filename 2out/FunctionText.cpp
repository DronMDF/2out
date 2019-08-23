// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "FunctionText.h"

using namespace std;
using namespace oout;

FunctionText::FunctionText(const function<string ()> &func)
	: func(func)
{
}

string FunctionText::asString() const
{
	return func();
}
