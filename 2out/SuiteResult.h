// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Result.h"
#include <list>
#include <memory>

namespace oout {

/// Test suite result set
class SuiteResult final : public Result {
public:
	/// Primary ctor
	explicit SuiteResult(const std::list<std::shared_ptr<const Result>> &results);

	/// Secondary ctor from variadic list of result
	template<typename... T>
	explicit SuiteResult(const std::shared_ptr<T> & ... tests)
		: SuiteResult(std::list<std::shared_ptr<const Result>>{
			tests...
		})
	{
	}

	/// Printer
	std::string print(const Format &format) const override;
private:
	const std::list<std::shared_ptr<const Result>> results;
};

}
