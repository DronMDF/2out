// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Result.h"
#include <list>
#include <memory>

namespace oout {

/// Test suite result set
class ResSuite final : public Result {
public:
	/// Primary ctor
	explicit ResSuite(const std::list<std::shared_ptr<const Result>> &results);

	/// Secondary ctor from variadic list of result
	template<typename... T>
	explicit ResSuite(const std::shared_ptr<T> & ... tests)
		: ResSuite(std::list<std::shared_ptr<const Result>>{
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
