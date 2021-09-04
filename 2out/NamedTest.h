// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include "Match.h"
#include "MatchTest.h"
#include "SuiteTest.h"
#include "Test.h"
#include "Text.h"

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

	/// Secondary ctor with matches
	template<typename... T>
	NamedTest(
		const std::string &name,
		const std::shared_ptr<const Text> &text,
		const std::shared_ptr<const Match> &match,
		const std::shared_ptr<T> & ... matches
	) : NamedTest(name, std::make_shared<const MatchTest>(text, match, matches...))
	{
	}

	/// Get test result
	std::unique_ptr<const Result> result() const override;

private:
	const std::string name;
	const std::shared_ptr<const Test> test;
};

}
