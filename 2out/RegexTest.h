// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Test.h"

namespace oout {

class Text;

class RegexTest final : public Test {
public:
	/// Primary ctor
	RegexTest(const std::shared_ptr<const Text> &text, const std::string &re);

	RegexTest(const std::string &text, const std::string &re);

	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Test> test;
};

}
