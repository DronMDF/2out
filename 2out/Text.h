// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>

namespace oout {

/// Abstract text
class Text {
public:
	/// Virtual dtor
	virtual ~Text() = default;

	/// Get value as string
	virtual std::string asString() const = 0;
};

}
