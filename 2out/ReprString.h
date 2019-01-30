// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Representation.h"

namespace oout {

/// Representation for string
class ReprString final : public Representation {
public:
	/// Primary ctor
	explicit ReprString(const std::string &value);

	/// Get value as string
	std::string asString() const override;
private:
	const std::string value;
};

}
