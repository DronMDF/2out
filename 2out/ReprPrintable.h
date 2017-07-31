// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <sstream>
#include "Representation.h"

namespace oout {

/// Representation for any printable type
template <typename T>
class ReprPrintable final : public Representation {
public:
	explicit ReprPrintable(const T &value)
		: value(value)
	{
	}

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
