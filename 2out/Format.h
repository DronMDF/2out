// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <chrono>
#include <list>
#include <memory>

namespace oout {

class Result;

/// Abstract format for convert results to string
class Format {
public:
	/// virtual dtor
	virtual ~Format() = default;

	/// Format success result
	virtual std::string success(const std::string &text) const = 0;

	/// Format failure result
	virtual std::string failure(const std::string &text) const = 0;

	/// Format error result
	virtual std::string error(const std::string &text) const = 0;

	/// Format simple test result
	virtual std::string test(
		const std::string &name,
		const std::shared_ptr<const Result> &assertion_result,
		const std::chrono::nanoseconds &duration
	) const = 0;

	/// Format suite result
	virtual std::string suite(
		const std::string &name,
		const std::chrono::nanoseconds &duration,
		const std::list<std::shared_ptr<const Result>> &nodes
	) const = 0;
};

}
