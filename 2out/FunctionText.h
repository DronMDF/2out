// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <functional>
#include "Text.h"

namespace oout {

/// Text for any string function
class FunctionText final : public Text {
public:
	/// Primary ctor
	explicit FunctionText(const std::function<std::string ()> &func);

	// @todo #311 ReprCallable with implicit binding
	//  template ctor with params binding

	/// Get value as string
	std::string asString() const override;
private:
	const std::function<std::string ()> func;
};

}
