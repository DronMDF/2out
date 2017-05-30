// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <ResSimple.h>

using namespace oout;

ResSimple::ResSimple(bool status)
	: status(status)
{
}

size_t ResSimple::failures() const
{
	return status ? 0 : 1;
}
