// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CountError.h"
#include <numeric>
#include "Format.h"
#include "SuiteResult.h"

using namespace std;
using namespace oout;

namespace oout {

class FmtError final : public Format {
public:
	string success(const string &) const override
	{
		return {};
	}

	string failure(const string &) const override
	{
		return {};
	}

	string error(const string &) const override
	{
		return "E";
	}

	string test(
		const string &,
		const shared_ptr<const Result> &assertion_result,
		const chrono::nanoseconds &
	) const override
	{
		return assertion_result->print(*this);
	}

	string suite(
		const string &,
		const chrono::nanoseconds &,
		const list<shared_ptr<const Result>> &results
	) const override
	{
		return accumulate(
			results.begin(),
			results.end(),
			string{},
			[this](const string &v, const auto &r){
				return v + r->print(*this);
			}
		);
	}
};

}  // namespace oout

CountError::CountError(const list<shared_ptr<const Result>> &results)
	: CountError(make_unique<SuiteResult>(results))
{
}

CountError::CountError(const shared_ptr<const Result> &result)
	: result(result)
{
}

size_t CountError::count() const
{
	return result->print(FmtError()).size();
}
