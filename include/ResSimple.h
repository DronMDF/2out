// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Result.h"

namespace oout {

class ResSimple final : public Result {
public:
	// @todo #94:15min Arg time is not need in ResSimple
	//  ResSimple can always pass 0 to Format
	ResSimple(const std::string &name, bool failure, float time);

	std::string print(const Format &format) const override;
private:
	const std::string name;
	bool failure;
	float time;
};

}