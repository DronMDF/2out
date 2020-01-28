// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

namespace oout {

class Result;
class Text;

class Match {
public:
	virtual ~Match() = default;

	virtual std::unique_ptr<const Result> match(
		const std::shared_ptr<const Text> &b
	) const = 0;
};

}
