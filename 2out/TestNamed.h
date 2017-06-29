// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include "Test.h"

namespace oout {

/// TestNamed is a Test decorator.
/// Adds a name to the test or test suite
class TestNamed final : public Test {
public:
	TestNamed(const std::string &name, const std::list<std::shared_ptr<const Test>> &tests);
	TestNamed(const std::string &name, const std::shared_ptr<const Test> &test);
	std::shared_ptr<const Result> result() const override;
private:
	const std::string name;
	const std::shared_ptr<const Test> test;
};

}