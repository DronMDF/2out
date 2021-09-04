// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "../Test.h"
#include "../SuiteTest.h"
#include "../NamedTest.h"

namespace oout {
namespace dirty {

class Test : public oout::Test {
public:
	explicit Test(const std::shared_ptr<const oout::Test> &tests);

	template<typename ... T>
	Test(
		const std::shared_ptr<const oout::Test> &a,
		const std::shared_ptr<const oout::Test> &b,
		const T & ... tests
	) : Test(std::make_shared<oout::SuiteTest>(a, b, tests...))
	{
	}

	template<typename ... T>
	Test(
		const std::string &name,
		const T & ... tests
	) : Test(std::make_shared<oout::NamedTest>(name, tests...))
	{
	}

	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const oout::Test> tests;
};

}
}
