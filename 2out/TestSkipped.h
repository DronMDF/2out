// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Test.h"

namespace oout {

/// TestSkipped is a Test decorator.
/// All test, passed to this decorator mark success without execution
/// Test not keep inner tests structure. If you pass TestSuite, he looks like as simple test.
class TestSkipped final : public Test {
public:
	explicit TestSkipped(const std::shared_ptr<const Test> &test);
	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Test> test;
};

}
