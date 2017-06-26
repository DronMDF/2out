// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Representation.h"
#include "Test.h"

namespace oout {

class TestContainText final : public Test {
public:
	TestContainText(const std::shared_ptr<const Representation> &repr, const std::string &text);

	std::shared_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Representation> repr;
	const std::string text;
};

}
