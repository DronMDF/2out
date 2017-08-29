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

/// Suite of tests
class TestSuite final : public Test {
public:
	/// Primary ctor
	explicit TestSuite(const std::list<std::shared_ptr<const Test>> &cases);

	/// Get test suite result
	std::unique_ptr<const Result> result() const override;
private:
	const std::list<std::shared_ptr<const Test>> cases;
};

}
