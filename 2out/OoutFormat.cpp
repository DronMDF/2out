// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "OoutFormat.h"
#include <sstream>
#include "CountFailure.h"
#include "CountError.h"
#include "Result.h"

using namespace std;
using namespace oout;

string OoutFormat::success(const string &text [[maybe_unused]]) const
{
	return {};
}

string OoutFormat::failure(const string &text) const
{
	return text;
}

string OoutFormat::error(const string &text) const
{
	return text;
}

string OoutFormat::test(
	const string &name,
	const shared_ptr<const Result> &assertion_result,
	const chrono::nanoseconds &duration [[maybe_unused]]
) const
{
	ostringstream out;
	if (CountFailure(assertion_result).count() > 0) {
		out << "FAILURE: " << name << endl;
		out << "\t" << assertion_result->print(*this) << endl;
	}
	if (CountError(assertion_result).count() > 0) {
		out << "ERROR: " << name << endl;
		out << "\t" << assertion_result->print(*this) << endl;
	}
	return out.str();
}

string OoutFormat::suite(
	const string &name [[maybe_unused]],
	const chrono::nanoseconds &duration [[maybe_unused]],
	const list<shared_ptr<const Result>> &results
) const
{
	ostringstream out;
	for (const auto &r : results) {
		out << r->print(*this);
	}
	return out.str();
}
