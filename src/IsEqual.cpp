// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <IsEqual.h>
#include <memory>
#include <Failure.h>
#include <Success.h>

using namespace std;
using namespace oout;

IsEqual::IsEqual(int a, int b)
	: a(a), b(b)
{
}

shared_ptr<const AssertionResult> IsEqual::check() const
{
	shared_ptr<const AssertionResult> result;
	if (a == b) {
		result = make_shared<Success>();
	} else {
		result = make_shared<Failure>();
	}
	return result;
}
