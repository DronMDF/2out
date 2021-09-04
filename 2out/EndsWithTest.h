// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Test.h"

namespace oout {

class Text;

/// Test for string ends with suffix
class EndsWithTest final : public Test {
public:
	/// Primary ctor
	EndsWithTest(const std::shared_ptr<const Text> &a, const std::string &b);

	/// Secondary ctor from two strings
	EndsWithTest(const std::string &a, const std::string &b);

	/// Get result
	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Test> test;
};

}
