// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <AssertionResult.h>

using namespace oout;

AssertionResult::AssertionResult(bool success)
	: success(success)
{
}

AssertionResult::operator bool() const
{
	return success;
}
