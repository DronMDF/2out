// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Representation.h"

namespace oout {

class ReprSigned final : public Representation {
public:
	explicit ReprSigned(int64_t value);
	std::string asString() const override;
private:
	int64_t value;
};

}
