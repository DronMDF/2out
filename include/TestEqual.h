// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <sstream>
#include "Representation.h"
#include "Test.h"

namespace oout {

// @todo #175:15min TestEqual should have ctors with strings
class TestEqual final : public Test {
public:
	TestEqual(const std::shared_ptr<const Representation> &a, const std::string &b);

	TestEqual(
		const std::shared_ptr<const Representation> &a,
		const std::shared_ptr<const Representation> &b
	);

	std::shared_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Representation> a;
	const std::shared_ptr<const Representation> b;
};

}

