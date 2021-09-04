// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Match.h"
#include <string>

namespace oout {

class EndsWithMatch final : public Match {
public:
	explicit EndsWithMatch(const std::string &text);

	std::unique_ptr<const Result> match(
		const std::shared_ptr<const Text> &in
	) const override;

private:
	const std::string text;
};

}
