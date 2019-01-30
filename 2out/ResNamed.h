// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Result.h"

namespace oout {

/// ResNamed is a Result decorator
/// Add test name to result
class ResNamed final : public Result {
public:
	/// Primary ctor
	ResNamed(const std::string &name, const std::shared_ptr<const Result> &result);

	/// Printer
	std::string print(const Format &format) const override;
private:
	const std::string name;
	const std::shared_ptr<const Result> result;
};

}
