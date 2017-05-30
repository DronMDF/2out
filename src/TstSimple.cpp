// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TstSimple.h>
#include <Assertion.h>
#include <Result.h>

using namespace std;
using namespace oout;

TstSimple::TstSimple(const string &description, unique_ptr<const Assertion> assert)
	: description(description), assert(move(assert))
{
}

shared_ptr<const Result> TstSimple::result() const
{
	return make_shared<const Result>(
		"testcase",
		map<string, string>{
			make_pair("name", description),
			make_pair("failures", assert->valid() ? "0" : "1")
		},
		list<shared_ptr<const Result>>{}
	);
}
