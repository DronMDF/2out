// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>
#include <string>
#include "Test.h"

namespace oout {

/// Suite of tests
class SuiteTest final : public Test {
public:
	/// Primary ctor
	explicit SuiteTest(const std::list<std::shared_ptr<const Test>> &cases);

	/// Secondary ctor from variadic list of tests
	template<typename... T>
	explicit SuiteTest(
			const std::shared_ptr<const Test> &test1,
			const std::shared_ptr<T> & ... tests
		) : SuiteTest(std::list<std::shared_ptr<const Test>>{
			test1, tests...
		})
	{
	}

	/// Get test suite result
	std::unique_ptr<const Result> result() const override;
private:
	const std::list<std::shared_ptr<const Test>> cases;
};

}
