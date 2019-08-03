// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Test.h"

namespace oout {

/// SkippedTest is a Test decorator.
/// All test, passed to this decorator mark success without execution
/// Test not keep inner tests structure. If you pass SuiteTest, it looks like as simple test.
class SkippedTest final : public Test {
public:
	/// Primary ctor
	explicit SkippedTest(const std::shared_ptr<const Test> &test);

	/// Get test result
	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Test> test;
};

}
