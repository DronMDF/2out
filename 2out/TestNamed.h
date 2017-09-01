// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include "Test.h"
#include "TestSuite.h"

namespace oout {

/// TestNamed is a Test decorator.
/// Adds a name to the test or test suite
class TestNamed final : public Test {
public:
	/// Primary ctor
	TestNamed(const std::string &name, const std::shared_ptr<const Test> &test);

	/// Secondary ctor from TestNamed (Named Suite case)
	TestNamed(const std::string &name, const std::shared_ptr<const TestNamed> &test);

	/// Secondary ctor from list
	TestNamed(const std::string &name, const std::list<std::shared_ptr<const Test>> &tests);

	/// Secondary ctor from variadic list of tests
	template<typename... T>
	TestNamed(
		const std::string &name,
		const std::shared_ptr<const Test> &test,
		const std::shared_ptr<T> & ... tests
	) : TestNamed(name, std::make_shared<const TestSuite>(test, tests...))
	{
	}

	/// Get test result
	std::unique_ptr<const Result> result() const override;

private:
	const std::string name;
	const std::shared_ptr<const Test> test;
};

}
