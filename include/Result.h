// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstddef>
#include <list>
#include <map>
#include <memory>
#include <string>

namespace oout {

class Result final {
public:
	Result(
		const std::string &tag,
		const std::map<std::string, std::string> &attributes,
		const std::list<std::shared_ptr<const Result>> &nodes
	);

	virtual size_t failures() const;

	// @todo #43:15min Need to return tests (count of tests)
	// @todo #43:15min Need to print values to media
private:
	const std::string tag;
	const std::map<std::string, std::string> attributes;
	const std::list<std::shared_ptr<const Result>> nodes;
};

}
