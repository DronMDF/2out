// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <chrono>
#include <memory>
#include "Result.h"

namespace oout {

/// Result decorator of test with diration
class TimedResult final : public Result {
public:
	/// Primary ctor
	TimedResult(
		const std::shared_ptr<const Result> &result,
		const std::chrono::nanoseconds &duration
	);

	/// Printer
	std::string print(const Format &format) const override;
private:
	const std::shared_ptr<const Result> result;
	const std::chrono::nanoseconds duration;
};

}
