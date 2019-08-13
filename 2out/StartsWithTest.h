// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Test.h"

namespace oout {

class Text;

// @todo #259 Nonintuitive arg names in TestStartWith ctors

/// Test for string start with prefix
class StartsWithTest final : public Test {
public:
	/// Primary ctor from Text and string
	StartsWithTest(const std::shared_ptr<const Text> &a, const std::string &b);

	/// Secondary ctor from two strings
	StartsWithTest(const std::string &a, const std::string &b);

	/// Get result
	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Test> test;
};

}
