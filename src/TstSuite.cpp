// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TstSuite.h>
#include <numeric>
#include <Result.h>

using namespace std;
using namespace oout;

TstSuite::TstSuite(const string &description, const list<shared_ptr<const Test>> &cases)
	: description(description), cases(cases)
{
}

shared_ptr<const Result> TstSuite::result() const
{
	list<shared_ptr<const Result>> results;
	for (const auto &c : cases) {
		results.push_back(c->result());
	}
	return make_shared<Result>(
		"testsuite",
		map<string, string>{
			make_pair("name", description),
			make_pair(
				"failures",
				to_string(
					accumulate(
						results.begin(),
						results.end(),
						0,
						[](size_t v, const auto &r){
							return v + r->failures();
						}
					)
				)
			)
		},
		results
	);
}
