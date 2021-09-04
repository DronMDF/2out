// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Text.h"

namespace oout {

/// Text for signed integer
class SignedText final : public Text {
public:
	/// Primary ctor
	explicit SignedText(int64_t value);

	/// Get value as string
	std::string asString() const override;

private:
	int64_t value;
};

}
