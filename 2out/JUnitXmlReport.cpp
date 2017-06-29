// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <JUnitXmlReport.h>
#include <sstream>
#include <AssertionResult.h>
#include <FailureCount.h>
#include <Format.h>
#include <Result.h>
#include <TestCount.h>

using namespace std;
using namespace oout;

class FmtJunitXml final : public Format {
public:
	string success(const string &) const override
	{
		return {};
	}

	string failure(const string &text) const override
	{
		ostringstream out;
		out << "<failure><![CDATA[" << text << "]]></failure>" << endl;
		return out.str();
	}

	string error(const string &text) const override
	{
		ostringstream out;
		out << "<error><![CDATA[" << text << "]]></error>" << endl;
		return out.str();
	}

	string test(
		const string &name,
		const shared_ptr<const AssertionResult> &assertion_result,
		float time
	) const override
	{
		ostringstream out;
		out << "<testcase "
			<< "name='" << name << "' "
			<< "time='" << time << "'>" << endl
			<< assertion_result->print(*this)
			<< "</testcase>" << endl;
		return out.str();
	}

	string suite(
		const string &name,
		float time,
		const list<shared_ptr<const Result>> &results
	) const override
	{
		const auto test_count = TestCount(results).count();
		const auto failure_count = FailureCount(results).count();
		// @todo #210:15min Calculate error count for xml report

		ostringstream out;
		out << "<testsuite "
			<< "name='" << name << "' "
			<< "tests='" << test_count << "' "
			<< "errors='" << failure_count << "' "
			<< "failures='" << failure_count << "' "
			<< "time='" << time << "'>"
			<< endl;

		for (const auto &r : results) {
			out << r->print(*this);
		}

		out << "</testsuite>" << endl;
		return out.str();
	}
};

JUnitXmlReport::JUnitXmlReport(const std::shared_ptr<const Result> &result)
	: result(result)
{
}

string JUnitXmlReport::asString() const
{
	const auto failure_count = FailureCount(result).count();

	ostringstream out;
	out << "<?xml version='1.0' encoding='UTF-8'?>" << endl;
	out << "<testsuites "
		<< "errors='" << failure_count << "' "
		<< "failures='" << failure_count << "'>"
		<< endl;

	FmtJunitXml format;
	out << result->print(format);

	out << "</testsuites>" << endl;
	return out.str();
}

