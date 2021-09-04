// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Result.h"

namespace oout {

/// NamedResult is a Result decorator
/// Add test name to result
class NamedResult final : public Result {
public:
	/// Primary ctor
	NamedResult(const std::string &name, const std::shared_ptr<const Result> &result);

	/// Printer
	std::string print(const Format &format) const override;
private:
	const std::string name;
	const std::shared_ptr<const Result> result;
};

}
