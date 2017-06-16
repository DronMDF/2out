// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

namespace oout {

class AssertionResult;

class Assertion {
public:
	virtual ~Assertion() = default;
	virtual std::shared_ptr<const AssertionResult> check() const = 0;
};

}
