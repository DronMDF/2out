// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <FailureCount.h>
#include <numeric>
#include <Format.h>
#include <ResSuite.h>
#include <Result.h>

using namespace std;
using namespace oout;

class FmtFailures final : public Format {
public:
	string success(const string &) const override
	{
		return {};
	}

	string test(const string &, bool failure, float) const override
	{
		return failure ? "F" : "";
	}

	string suite(
		const string &,
		float,
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

FailureCount::FailureCount(const list<shared_ptr<const Result>> &results)
	: FailureCount(make_shared<ResSuite>("", results))
{
}

FailureCount::FailureCount(const shared_ptr<const Result> &result)
	: result(result)
{
}

size_t FailureCount::count() const
{
	FmtFailures format;
	return result->print(format).size();
}
