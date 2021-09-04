// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <sstream>
#include "Text.h"

namespace oout {

/// Text for any printable type
template <typename T>
class PrintableText final : public Text {
public:
	/// Primary ctor
	explicit PrintableText(const T &value)
		: value(value)
	{
	}

	/// Get value as string
	std::string asString() const override
	{
		std::ostringstream out;
		out << std::boolalpha << value;
		return out.str();
	}
private:
	const T value;
};

}
