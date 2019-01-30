// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ReprCallable.h"

using namespace std;
using namespace oout;

ReprCallable::ReprCallable(const function<string ()> &func)
	: func(func)
{
}

/// Get value as string
string ReprCallable::asString() const
{
	return func();
}
