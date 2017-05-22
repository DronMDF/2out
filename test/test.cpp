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
	const auto result = TstSuite(
		"Example suite",
		list<shared_ptr<const Test>>{
			make_shared<const TstSimple>(
				"2 * 2 should be equal 4",
				make_unique<const AssertionEqual>(2 * 2, 4)
			),
			make_shared<const TstSuite>(
				"Sub Suite",
				list<shared_ptr<const Test>>{
					make_shared<const TstSimple>(
						"2 + 2 should be equal 4",
						make_unique<const AssertionEqual>(2 + 2, 4)
					)
				}
			)
		}
	).result();

	return result ? 0 : -1;
}
