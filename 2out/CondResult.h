// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Result.h"

namespace oout {

class CondResult final : public Result {
public:
	CondResult(bool cond, const std::string &message);
	std::string print(const Format &format) const override;
private:
	const bool cond;
	const std::string message;
};

}
