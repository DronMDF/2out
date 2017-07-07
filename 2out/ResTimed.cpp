// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ResTimed.h"
#include "Format.h"

using namespace std;
using namespace oout;

namespace oout {

class FmtTimed final : public Format {
public:
	FmtTimed(const Format *format, float time)
		: format(format), time(time)
	{
	}

	string success(const string &text) const override
	{
		return format->success(text);
	}

	string failure(const string &text) const override
	{
		return format->failure(text);
	}

	string error(const string &text) const override
	{
		return format->error(text);
	}

	string test(const string &name,
		const shared_ptr<const Result> &assertion_result,
		float
	) const override
	{
		return format->test(name, assertion_result, time);
	}

	string suite(
		const string &name,
		float,
		const list<shared_ptr<const Result>> &results
	) const override
	{
		return format->suite(name, time, results);
	}

private:
	FmtTimed(const FmtTimed&) = delete;
	FmtTimed &operator =(const FmtTimed&) = delete;

	const Format *format;
	const float time;
};

}  // namespace oout

ResTimed::ResTimed(const shared_ptr<const Result> &result, float time)
	: result(result), time(time)
{
}

string ResTimed::print(const Format &format) const
{
	return result->print(FmtTimed(&format, time));
}
