// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <functional>
#include "Text.h"

namespace oout {

class MethodExceptionText final : public Text {
public:
	template <typename... A>
	explicit MethodExceptionText(const A & ... args)
		: invoker(std::bind(args...))
	{
	}

	std::string asString() const override;

private:
	const std::function<void ()> invoker;
};

}
