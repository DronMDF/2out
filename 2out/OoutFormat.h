// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Format.h"

namespace oout {

class OoutFormat final : public Format {
public:
	std::string success(const std::string &text) const override;
	std::string failure(const std::string &text) const override;
	std::string error(const std::string &) const override;
	std::string test(
		const std::string &name,
		const std::shared_ptr<const Result> &assertion_result,
		const std::chrono::nanoseconds &duration
	) const override;
	std::string suite(
		const std::string &name,
		const std::chrono::nanoseconds &duration,
		const std::list<std::shared_ptr<const Result>> &results
	) const override;
};

}
