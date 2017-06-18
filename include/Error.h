// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>
#include "AssertionResult.h"

namespace oout {

// @todo #111:15min Error should incapsulate error text
class Error final : public AssertionResult {
public:
	explicit Error(const std::string &text);
	operator bool() const override;
};

}
