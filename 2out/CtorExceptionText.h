// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <stdexcept>
#include "Text.h"

namespace oout {

// @todo #436 CtorExceptionText should create objects with params

/// Text for class, throw exception from ctor
template <typename T>
class CtorExceptionText final : public Text {
public:
	/// Exception message return as a string
	std::string asString() const override
	{
		try {
			T _;
			throw std::runtime_error("Class don't throw exception");
		} catch (const std::exception &e) {
			return e.what();
		}
	}
};

}
