// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Test.h"

namespace oout {

class TestTimed final : public Test {
public:
	explicit TestTimed(const std::shared_ptr<const Test> &test);
	std::shared_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Test> test;
};

}
