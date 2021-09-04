// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <functional>
#include <stdexcept>
#include "Text.h"

namespace oout {

/// Text for class, throw exception from ctor
template <typename T>
class CtorExceptionText final : public Text {
public:
	template <typename... A>
	explicit CtorExceptionText(const A & ... args)
		: invoker([&]{ T(args...); })
	{
	}

	/// Exception message return as a string
	std::string asString() const override
	{
		try {
			invoker();
		} catch (const std::exception &e) {
			return e.what();
		}
		throw std::runtime_error("Class ctor don't throw exception");
	}
private:
	const std::function<void ()> invoker;
};

}
