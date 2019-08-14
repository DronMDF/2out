// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Result.h"

namespace oout {

// @todo #383 TestResult should have constructor with bool and message
//  for omit CondResult in *Test code

/// Result of simple test
class TestResult final : public Result {
public:
	/// Primary ctor from assertion result
	explicit TestResult(const std::shared_ptr<const Result> &result);

	/// Printer
	std::string print(const Format &format) const override;
private:
	const std::shared_ptr<const Result> result;
};

}
