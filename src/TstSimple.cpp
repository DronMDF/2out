// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TstSimple.h>
#include <Assertion.h>

using namespace std;
using namespace oout;

TstSimple::TstSimple(const string &description, unique_ptr<const Assertion> assert)
	: assert(move(assert))
{
}

bool TstSimple::result() const
{
	return assert->valid();
}
