// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CountFailure.h"
#include <numeric>
#include "Format.h"
#include "SuiteResult.h"
#include "Result.h"

using namespace std;
using namespace oout;

namespace oout {

class FmtFailure final : public Format {
public:
	string success(const string &) const override
	{
		return {};
	}

	string failure(const string &) const override
	{
		return "F";
	}

	string error(const string &) const override
	{
		return {};
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

CountFailure::CountFailure(const list<shared_ptr<const Result>> &results)
	: CountFailure(make_unique<SuiteResult>(results))
{
}

CountFailure::CountFailure(const shared_ptr<const Result> &result)
	: result(result)
{
}

size_t CountFailure::count() const
{
	return result->print(FmtFailure()).size();
}
