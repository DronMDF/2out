// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <string>
#include "Test.h"

namespace oout {

class Assertion;

class TstSimple final : public Test {
public:
	TstSimple(const std::string &description, std::unique_ptr<const Assertion> assert);

	std::shared_ptr<const Result> result() const override;

private:
	const std::string description;
	const std::unique_ptr<const Assertion> assert;
};

}
