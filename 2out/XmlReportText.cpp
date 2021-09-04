// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "XmlReportText.h"
#include <sstream>
#include "CountError.h"
#include "CountFailure.h"
#include "CountTest.h"
#include "Format.h"
#include "Result.h"

using namespace std;
using namespace oout;

namespace oout {

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
		const shared_ptr<const Result> &assertion_result,
		const chrono::nanoseconds &duration
	) const override
	{
		const auto time = chrono::duration_cast<chrono::duration<float>>(duration).count();
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
		const chrono::nanoseconds &duration,
		const list<shared_ptr<const Result>> &results
	) const override
	{
		const auto count_test = CountTest(results).count();
		const auto count_failure = CountFailure(results).count();
		const auto count_error = CountError(results).count();
		const auto time = chrono::duration_cast<chrono::duration<float>>(duration).count();

		ostringstream out;
		out << "<testsuite "
		    << "name='" << name << "' "
		    << "tests='" << count_test << "' "
		    << "failures='" << count_failure << "' "
		    << "errors='" << count_error << "' "
		    << "time='" << time << "'>"
		    << endl;

		for (const auto &r : results) {
			out << r->print(*this);
		}

		out << "</testsuite>" << endl;
		return out.str();
	}
};

}  // namespace oout

XmlReportText::XmlReportText(const std::shared_ptr<const Result> &result)
	: result(result)
{
}

string XmlReportText::asString() const
{
	const auto failure_count = CountFailure(result).count();

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

