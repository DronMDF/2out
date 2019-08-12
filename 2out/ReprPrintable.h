// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <sstream>
#include "Text.h"

namespace oout {

// @todo #365 ReprPrintable should be named PrintableText
//  Or, may be, StreamText

/// Text for any printable type
template <typename T>
class ReprPrintable final : public Text {
public:
	/// Primary ctor
	explicit ReprPrintable(const T &value)
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
