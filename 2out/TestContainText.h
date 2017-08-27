// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Representation.h"
#include "Test.h"

namespace oout {

/// Test for substring present in string
class TestContainText final : public Test {
public:
	/// Secondary ctor from strings
	TestContainText(const std::string &text, const std::string &substr);

	/// Secondary ctor from string and Repr
	TestContainText(
		const std::string &text,
		const std::shared_ptr<const Representation> &substr
	);

	/// Secondary ctor from Repr and string
	TestContainText(
		const std::shared_ptr<const Representation> &text,
		const std::string &substr
	);

	/// Primary ctor
	TestContainText(
		const std::shared_ptr<const Representation> &text,
		const std::shared_ptr<const Representation> &substr
	);

	/// Test result
	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Representation> text;
	const std::shared_ptr<const Representation> substr;
};

}
