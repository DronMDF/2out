// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TimedResult.h"
#include "Format.h"

using namespace std;
using namespace oout;

namespace oout {

class FmtTimed final : public Format {
public:
	FmtTimed(const Format *format, const chrono::nanoseconds &duration)
		: format(format), duration(duration)
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

	string test(
		const string &name,
		const shared_ptr<const Result> &assertion_result,
		const chrono::nanoseconds &
	) const override
	{
		return format->test(name, assertion_result, duration);
	}

	string suite(
		const string &name,
		const chrono::nanoseconds &,
		const list<shared_ptr<const Result>> &results
	) const override
	{
		return format->suite(name, duration, results);
	}

private:
	FmtTimed(const FmtTimed&) = delete;
	FmtTimed &operator =(const FmtTimed&) = delete;

	const Format *format;
	const chrono::nanoseconds duration;
};

}  // namespace oout

TimedResult::TimedResult(
	const shared_ptr<const Result> &result,
	const chrono::nanoseconds &duration
) : result(result), duration(duration)
{
}

string TimedResult::print(const Format &format) const
{
	return result->print(FmtTimed(&format, duration));
}
