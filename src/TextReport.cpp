// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TextReport.h>
#include <sstream>
#include <AssertionResult.h>
#include <FailureCount.h>
#include <Format.h>
#include <Result.h>
#include <TestCount.h>

using namespace std;
using namespace oout;

class FmtText final : public Format {
public:
	string success(const string &) const override
	{
		// @todo #121:15min OK string should be visualized here.
		return {};
	}

	string failure(const string &) const override
	{
		// @todo #122:15min FAILED string should be visualized here.
		return {};
	}

	string error(const string &) const override
	{
		// @todo #123:15min ERROR string should be visualized here.
		//  I do not know how this message looked.
		return {};
	}

	string test(
		const string &name,
		const shared_ptr<const AssertionResult> &assertion_result,
		float time
	) const override
	{
		ostringstream out;
		out << "[ RUN      ] " << name << endl;
		out << (!*assertion_result ? "[  FAILED  ] " : "[       OK ] ") << name;
		out << " (" << int(time * 1000) << " ms)" << endl;
		return out.str();
	}

	string suite(
		const string &name,
		float time,
		const list<shared_ptr<const Result>> &results
	) const override
	{
		const auto test_count = TestCount(results).count();
		ostringstream out;
		out << "[----------] " << test_count << " test from " << name << endl;
		for (const auto &r : results) {
			out << r->print(*this);
		}
		out << "[----------] " << test_count << " test from " << name
			<< " (" << int(time * 1000) << " ms total)" << endl;
		return out.str();
	}
};

TextReport::TextReport(const std::shared_ptr<const Result> &result)
	: result(result)
{
}

string TextReport::asString() const
{
	const auto test_count = TestCount(result).count();
	ostringstream out;
	// @todo #82:15min gtest count of test cases. Is it need for me?
	out << "[==========] Running " << test_count << " tests" << endl;
	FmtText format;
	out << result->print(format);
	// @todo #82:15min gtest show total seconds.
	//  I have root suite, and this value show on inner level
	out << "[==========] " << test_count << " tests ran." << endl;

	const auto failure_count = FailureCount(result).count();
	out << "[  PASSED  ] " << test_count - failure_count << " test." << endl;
	if (failure_count > 0) {
		out << "[  FAILED  ] " << failure_count << " test." << endl;
		// @todo #82:15min gtest show list of failure tests.
		//  I can do this with special formatter
		out << failure_count << " FAILED TEST" << endl;
	}
	return out.str();
}
