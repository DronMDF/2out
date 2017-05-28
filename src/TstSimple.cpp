// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TstSimple.h>
#include <Assertion.h>
#include <ResSimple.h>

using namespace std;
using namespace oout;

TstSimple::TstSimple(const string &description, unique_ptr<const Assertion> assert)
	: description(description), assert(move(assert))
{
}

shared_ptr<const Result> TstSimple::result() const
{
	return make_shared<const ResSimple>(assert->valid());
}
