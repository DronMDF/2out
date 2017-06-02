// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>

namespace oout {

class Format {
public:
	virtual ~Format() = default;

	virtual std::string test(
		const std::string &name,
		bool failure,
		float time
	) const = 0;

	virtual std::string suite(
		const std::string &name,
		float time,
		const std::list<std::shared_ptr<const Result>> &nodes
	) const = 0;
};

}
