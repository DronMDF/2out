// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CountTest.h"
#include <numeric>
#include "Format.h"
#include "SuiteResult.h"

using namespace std;
using namespace oout;

namespace oout {

class FmtTests final : public Format {
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
		return {};
	}

	string test(
		const string &,
		const shared_ptr<const Result> &,
		const chrono::nanoseconds &
	) const override
	{
		return "T";
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

CountTest::CountTest(const list<shared_ptr<const Result>> &results)
	: CountTest(make_unique<SuiteResult>(results))
{
}

CountTest::CountTest(const shared_ptr<const Result> &result)
	: result(result)
{
}

size_t CountTest::count() const
{
	return result->print(FmtTests()).size();
}
