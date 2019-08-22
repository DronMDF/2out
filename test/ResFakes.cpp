// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ResFakes.h"
#include <2out/Error.h>
#include <2out/FailureResult.h>
#include <2out/Format.h>
#include <2out/Success.h>

using namespace std;
using namespace oout;

ResOkCase::ResOkCase(const string &name)
	: name(name)
{
}

string ResOkCase::print(const Format &format) const
{
	return format.test(name, make_shared<Success>(), chrono::nanoseconds::zero());
}

ResFailureCase::ResFailureCase(const string &name)
	: name(name)
{
}

string ResFailureCase::print(const Format &format) const
{
	return format.test(name, make_shared<FailureResult>(), chrono::nanoseconds::zero());
}

ResErrorCase::ResErrorCase(const string &name)
	: name(name)
{
}

string ResErrorCase::print(const Format &format) const
{
	return format.test(name, make_shared<Error>("error"), chrono::nanoseconds::zero());
}
