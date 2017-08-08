// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ResNamed.h"
#include "Format.h"

using namespace std;
using namespace oout;

namespace oout {

class FmtNamed final : public Format {
public:
	FmtNamed(const Format *format, const string &name)
		: format(format), name(name)
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

	string test(const string &,
		const shared_ptr<const Result> &assertion_result,
		const chrono::nanoseconds &duration
	) const override
	{
		return format->test(name, assertion_result, duration);
	}

	string suite(
		const string &,
		const chrono::nanoseconds &duration,
		const list<shared_ptr<const Result>> &results
	) const override
	{
		return format->suite(name, duration, results);
	}

private:
	FmtNamed(const FmtNamed&) = delete;
	FmtNamed &operator =(const FmtNamed&) = delete;

	const Format *format;
	const string name;
};

}  // namespace oout

ResNamed::ResNamed(const string &name, const shared_ptr<const Result> &result)
	: name(name), result(result)
{
}

string ResNamed::print(const Format &format) const
{
	return result->print(FmtNamed(&format, name));
}

