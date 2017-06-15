// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <IsEqual.h>
#include <AssertionResult.h>

using namespace oout;

IsEqual::IsEqual(int a, int b)
	: a(a), b(b)
{
}

AssertionResult IsEqual::check() const
{
	return AssertionResult(a == b);
}
