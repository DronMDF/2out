// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Result.h"

namespace oout {

/// Failure result
class FailureResult final : public Result {
public:
	/// Primary ctor with message
	explicit FailureResult(const std::string &text = std::string());

	/// Printer
	std::string print(const Format &format) const override;
private:
	const std::string text;
};

}
