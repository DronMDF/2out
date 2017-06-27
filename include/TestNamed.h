// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Test.h"

namespace oout {

class TestNamed final : public Test {
public:
	// @todo #191:15min Add ctor for list of tests. TestSuite make inside.
	TestNamed(const std::string &name, const std::shared_ptr<const Test> &test);
	std::shared_ptr<const Result> result() const override;
private:
	const std::string name;
	const std::shared_ptr<const Test> test;
};

}
