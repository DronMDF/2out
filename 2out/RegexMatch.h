// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Match.h"
#include <string>

namespace oout {

class RegexMatch final : public Match {
public:
	explicit RegexMatch(const std::string &re);

	std::unique_ptr<const Result> match(
		const std::shared_ptr<const Representation> &in
	) const override;

private:
	const std::string re;
};

}
