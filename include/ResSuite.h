// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Result.h"
#include <list>
#include <memory>

namespace oout {

class ResSuite final : public Result {
public:
	ResSuite(
		const std::string &name,
		float time,
		const std::list<std::shared_ptr<const Result>> &results
	);

	std::string print(const Format &format) const override;
	size_t failures() const override;
private:
	const std::string name;
	float time;
	const std::list<std::shared_ptr<const Result>> results;
};

}
