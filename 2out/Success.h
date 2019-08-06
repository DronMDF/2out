// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Result.h"

namespace oout {

// @todo #313 Class Success replaced by CondResult, need to remove

/// Successed result of test execution
class Success final : public Result {
public:
	/// Primary ctor
	explicit Success(const std::string &text = std::string());

	/// Printer
	std::string print(const Format &format) const override;
private:
	const std::string text;
};

}

