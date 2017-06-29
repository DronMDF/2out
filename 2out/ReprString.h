// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Representation.h"

namespace oout {

class ReprString final : public Representation {
public:
	explicit ReprString(const std::string &value);
	std::string asString() const override;
private:
	const std::string value;
};

}
