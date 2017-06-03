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

class Format;

class Result {
public:
	// @todo #70:15min Implement ResCase separately
	// @todo #70:15min Implement ResSuite separately and live this class is abstract
	Result()
		: Result("none", {}, {})
	{
	}

	Result(
		const std::string &tag,
		const std::map<std::string, std::string> &attributes,
		const std::list<std::shared_ptr<const Result>> &nodes
	);
	virtual ~Result() = default;

	virtual std::string print(const Format &format) const;

	// @todo #46:15min failures is outscope of result, extract to another class
	size_t failures() const;

	// @todo #43:15min Need to return tests (count of tests)
	//  This is out of scope for Result, need to introduce another class
private:
	const std::string tag;
	const std::map<std::string, std::string> attributes;
	const std::list<std::shared_ptr<const Result>> nodes;
};

}
