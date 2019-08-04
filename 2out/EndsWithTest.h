// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Representation.h"
#include "Test.h"

namespace oout {

/// Test for string ends with suffix
class EndsWithTest final : public Test {
public:
	/// Secondary ctor from two strings
	EndsWithTest(const std::string &a, const std::string &b);

	/// Secondary ctor from string and Repr
	EndsWithTest(const std::string &a, const std::shared_ptr<const Representation> &b);

	/// Secondary ctor from Repr and string
	EndsWithTest(const std::shared_ptr<const Representation> &a, const std::string &b);

	/// Primary ctor
	EndsWithTest(
		const std::shared_ptr<const Representation> &a,
		const std::shared_ptr<const Representation> &b
	);

	/// Get result
	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Representation> a;
	const std::shared_ptr<const Representation> b;
};

}