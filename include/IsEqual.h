// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Assertion.h"

namespace oout {

// @todo #13:15min IsEqual is a bad Assertion.
//  Right Assertion should get in args lazy objects, not int.
class IsEqual final : public Assertion {
public:
	IsEqual(int a, int b);
	std::shared_ptr<const AssertionResult> check() const override;
private:
	int a;
	int b;
};

}
