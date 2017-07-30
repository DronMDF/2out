// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Representation.h"
#include "Test.h"

namespace oout {

class TestStartsWith final : public Test {
public:
	TestStartsWith(const std::string &a, const std::string &b);
	TestStartsWith(const std::string &a, const std::shared_ptr<const Representation> &b);
	TestStartsWith(const std::shared_ptr<const Representation> &a, const std::string &b);

	TestStartsWith(
		const std::shared_ptr<const Representation> &a,
		const std::shared_ptr<const Representation> &b
	);

	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Representation> a;
	const std::shared_ptr<const Representation> b;
};

}


