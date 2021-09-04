// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Test.h"

namespace oout {

/// Test decorator for catch exceptions, and report error
class SafeTest final : public Test {
public:
	/// Primary ctor
	explicit SafeTest(const std::shared_ptr<const Test> &test);

	/// Get test result
	std::unique_ptr<const Result> result() const override;

private:
	const std::shared_ptr<const Test> test;
};

}
