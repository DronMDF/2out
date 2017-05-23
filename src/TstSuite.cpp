// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TstSuite.h>

using namespace std;
using namespace oout;

TstSuite::TstSuite(const string &description, const list<shared_ptr<const Test>> &cases)
	: cases(cases)
{
}

bool TstSuite::result() const
{
	for (const auto &c : cases) {
		if (!c->result()) {
			return false;
		}
	}
	return true;
}
