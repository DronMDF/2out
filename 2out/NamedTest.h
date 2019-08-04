// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include "Test.h"
#include "SuiteTest.h"

namespace oout {

/// NamedTest is a Test decorator.
/// Adds a name to the test or test suite
class NamedTest final : public Test {
public:
	/// Primary ctor
	NamedTest(const std::string &name, const std::shared_ptr<const Test> &test);

	/// Secondary ctor from NamedTest (Named Suite case)
	NamedTest(const std::string &name, const std::shared_ptr<const NamedTest> &test);

	/// Secondary ctor from list
	NamedTest(const std::string &name, const std::list<std::shared_ptr<const Test>> &tests);

	/// Secondary ctor from variadic list of tests
	template<typename... T>
	NamedTest(
		const std::string &name,
		const std::shared_ptr<const Test> &test1,
		const std::shared_ptr<const Test> &test2,
		const std::shared_ptr<T> & ... tests
	) : NamedTest(name, std::make_shared<const SuiteTest>(test1, test2, tests...))
	{
	}

	/// Get test result
	std::unique_ptr<const Result> result() const override;

private:
	const std::string name;
	const std::shared_ptr<const Test> test;
};

}