// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ResFakes.h"
#include <Failure.h>
#include <Format.h>
#include <Success.h>

using namespace std;
using namespace oout;

ResFailureCase::ResFailureCase(const string &name)
	: name(name)
{
}

string ResFailureCase::print(const Format &format) const
{
	return format.test(name, make_shared<Failure>(), 0);
}

ResOkCase::ResOkCase(const string &name)
	: name(name)
{
}

string ResOkCase::print(const Format &format) const
{
	return format.test(name, make_shared<Success>(), 0);
}
