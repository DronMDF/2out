// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Test.h"

namespace oout {

/// Test decorator for execution time meansure
class TestTimed final : public Test {
public:
	/// Primary ctor
	explicit TestTimed(const std::shared_ptr<const Test> &test);

	/// Get test result (with duration)
	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Test> test;
};

}
