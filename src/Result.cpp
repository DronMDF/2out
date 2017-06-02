// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <Result.h>
#include <Format.h>
#include <Report.h>

using namespace std;
using namespace oout;

Result::Result(
	const string &tag,
	const map<string, string> &attributes,
	const list<shared_ptr<const Result>> &nodes
)
	: tag(tag), attributes(attributes), nodes(nodes)
{
}

string Result::print(const Format &format) const
{
	// @todo #68:15min Use polymorphism instead if
	if (tag == "testcase") {
		return format.test(
			attributes.at("name"),
			attributes.at("failures") != "0",
			0
		);
	}

	if (tag == "testsuite") {
		return format.suite(
			attributes.at("name"),
			0,
			nodes
		);
	}

	throw runtime_error("Wrong node type");
}

size_t Result::failures() const
{
	return stoi(attributes.at("failures"));
}
