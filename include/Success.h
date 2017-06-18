// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "AssertionResult.h"

namespace oout {

// @todo #111:15min Success should incapsulate text
class Success final : public AssertionResult {
public:
	std::string print(const Format &format) const override;
	operator bool() const override;
};

}

