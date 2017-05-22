// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <2out.h>

using namespace std;
using namespace oout;

int main(int, char **)
{
	const auto result = Suite(
		"Example suite",
		{
			make_shared<const Case>(
				"2 * 2 should be equal 4",
				make_unique<const AssertionEqual>(2 * 2, 4)
			),
		}
	).run();

	return result ? 0 : -1;
}
