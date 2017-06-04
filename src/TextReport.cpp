// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TextReport.h>
#include <sstream>
#include <Format.h>
#include <Result.h>

using namespace std;
using namespace oout;

// @todo #29:15min Count test with special representations
//  number of tests used in some places of TextReport and FmtText
class FmtText final : public Format {
public:
	string test(const string &name, bool failure, float time) const override
	{
		ostringstream out;
		out << "[ RUN      ] " << name << endl;
		out << (failure ? "[  FAILED  ] " : "[       OK ] ") << name;
		out << " (" << int(time * 1000) << " ms)" << endl;
		return out.str();
	}

	string suite(
		const string &name,
		float time,
		const list<shared_ptr<const Result>> &results
	) const override
	{
		ostringstream out;
		out << "[----------] 2 test from " << name << endl;
		for (const auto &r : results) {
			out << r->print(*this);
		}
		out << "[----------] 2 test from " << name << " (" << int(time * 1000) << " ms total)" << endl;
		return out.str();
	}
};

TextReport::TextReport(const std::shared_ptr<const Result> &result)
	: result(result)
{
}

string TextReport::asString() const
{
	FmtText format;
	ostringstream out;
	out << "[==========] Running" << endl;
	out << result->print(format);
	out << "[==========] tests run" << endl;
	return out.str();
}
