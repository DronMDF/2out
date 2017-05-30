// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Result.h"

namespace oout {

// @todo #32:15min ResSimple should print out to media
class ResSimple final : public Result {
public:
	// @todo #32:15min ResSimple should keep more parameters
	explicit ResSimple(bool status);
	size_t failures() const override;
private:
	bool status;
};

}
