// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Test.h"

namespace oout {

class Text;

/// Equality test
class EqualTest final : public Test {
public:
	/// Primary ctor from Repr and string
	EqualTest(const std::shared_ptr<const Text> &a, const std::string &b);

	/// Secondary ctor from two string
	EqualTest(const std::string &a, const std::string &b);

	/// Get result
	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Test> test;
};

}
