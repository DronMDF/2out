// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <IsEqual.h>
#include <memory>
#include <AssertionResult.h>

using namespace std;
using namespace oout;

IsEqual::IsEqual(int a, int b)
	: a(a), b(b)
{
}

shared_ptr<const AssertionResult> IsEqual::check() const
{
	return make_shared<AssertionResult>(a == b);
}
