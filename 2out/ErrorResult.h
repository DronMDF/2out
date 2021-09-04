// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>
#include "Result.h"

namespace oout {

class ErrorResult final : public Result {
public:
	/// Primary ctor with error message
	explicit ErrorResult(const std::string &text = std::string());

	/// Printer
	std::string print(const Format &format) const override;
private:
	const std::string text;
};

}
