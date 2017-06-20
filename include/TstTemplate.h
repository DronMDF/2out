// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <string>
#include "ResSimple.h"
#include "Test.h"
#include "Error.h"

namespace oout {

class Assertion;

template <typename O, typename A>
class TstTemplate final : public Test {
public:
	TstTemplate(
		const std::string &description,
		const std::shared_ptr<const O> &object,
		std::unique_ptr<const A> assertion
	) : description(description), object(object), assertion(move(assertion))
	{
	}

	std::shared_ptr<const Result> result() const override
	{
		std::shared_ptr<const AssertionResult> assertion_result;
		try {
			assertion_result = assertion->check(object);
		} catch (const std::exception &e) {
			assertion_result = std::make_shared<Error>(e.what());
		}
		return std::make_shared<const ResSimple>(
			description,
			assertion_result
		);
	}

private:
	const std::string description;
	const std::shared_ptr<const O> object;
	const std::unique_ptr<const A> assertion;
};

}

