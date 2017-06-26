// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>
#include <string>
#include "Test.h"

namespace oout {

// @todo #173:15min Remove description from TestSuite
class TestSuite final : public Test {
public:
	TestSuite(
		const std::string &description,
		const std::list<std::shared_ptr<const Test>> &cases
	);

	std::shared_ptr<const Result> result() const override;

private:
	const std::string description;
	const std::list<std::shared_ptr<const Test>> cases;
};

}
