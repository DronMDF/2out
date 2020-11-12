// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MethodExceptionText.h"
#include <stdexcept>

using namespace std;
using namespace oout;

string MethodExceptionText::asString() const
{
	try {
		invoker();
	} catch (const exception &e) {
		return e.what();
	}
	throw runtime_error("Class method don't throw exception");
}
