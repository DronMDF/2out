// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TextReportText.h"
#include <sstream>
#include "CountFailure.h"
#include "CountTest.h"
#include "Format.h"
#include "Result.h"

using namespace std;
using namespace oout;

namespace oout {

class FmtText final : public Format {
public:
	string success(const string &text) const override
	{
		ostringstream out;
		out << text << endl << "[       OK ] ";
		return out.str();
	}

	string failure(const string &text) const override
	{
		ostringstream out;
		out << text << endl << "[  FAILED  ] ";
		return out.str();
	}

	string error(const string &) const override
	{
		// @todo #123:15min ERROR string should be visualized here.
		//  I do not know how this message looked.
		return {};
	}

	string test(
		const string &name,
		const shared_ptr<const Result> &assertion_result,
		const chrono::nanoseconds &duration
	) const override
	{
		const auto ms = chrono::duration_cast<chrono::milliseconds>(duration).count();
		ostringstream out;
		out << "[ RUN      ] " << name << endl
		    << assertion_result->print(*this) << name
		    << " (" << ms << " ms)" << endl;
		return out.str();
	}

	string suite(
		const string &name,
		const chrono::nanoseconds &duration,
		const list<shared_ptr<const Result>> &results
	) const override
	{
		const auto test_count = CountTest(results).count();
		ostringstream out;
		out << "[----------] " << test_count << " test from " << name << endl;
		for (const auto &r : results) {
			out << r->print(*this);
		}
		const auto ms = chrono::duration_cast<chrono::milliseconds>(duration).count();
		out << "[----------] " << test_count << " test from " << name
		    << " (" << ms << " ms total)" << endl;
		return out.str();
	}
};

}  // namespace oout

TextReportText::TextReportText(const std::shared_ptr<const Result> &result)
	: result(result)
{
}

string TextReportText::asString() const
{
	const auto test_count = CountTest(result).count();
	ostringstream out;
	// @todo #82:15min gtest count of test cases. Is it need for me?
	out << "[==========] Running " << test_count << " tests" << endl;
	FmtText format;
	out << result->print(format);
	// @todo #82:15min gtest show total seconds.
	//  I have root suite, and this value show on inner level
	out << "[==========] " << test_count << " tests ran." << endl;

	const auto failure_count = CountFailure(result).count();
	out << "[  PASSED  ] " << test_count - failure_count << " test." << endl;
	if (failure_count > 0) {
		out << "[  FAILED  ] " << failure_count << " test." << endl;
		// @todo #82:15min gtest show list of failure tests.
		//  I can do this with special formatter
		out << failure_count << " FAILED TEST" << endl;
	}
	return out.str();
}
