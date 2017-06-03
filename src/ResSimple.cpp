// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <ResSimple.h>
#include <Format.h>

using namespace std;
using namespace oout;

ResSimple::ResSimple(const string &name, bool failure, float time)
	: name(name), failure(failure), time(time)
{
}

string ResSimple::print(const Format &format) const
{
	return format.test(name, failure, time);
}

size_t ResSimple::failures() const
{
	return failure ? 1 : 0;
}
