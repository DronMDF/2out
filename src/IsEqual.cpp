// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <IsEqual.h>

using namespace std;
using namespace oout;

IsEqual::IsEqual(int a, int b)
	: a(a), b(b)
{
}

bool IsEqual::valid() const
{
	return a == b;
}