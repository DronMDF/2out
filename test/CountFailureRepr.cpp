// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CountFailureRepr.h"
#include <2out/CountFailure.h>

using namespace std;
using namespace oout;

CountFailureRepr::CountFailureRepr(const shared_ptr<const CountFailure> &count)
	: count(count)
{
}

string CountFailureRepr::asString() const
{
	return to_string(count->count());
}
