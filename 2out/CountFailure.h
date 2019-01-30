// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>

namespace oout {

class Result;

/// Number of failures in test result
class CountFailure final {
public:
	/// Secondary ctor from result list
	explicit CountFailure(const std::list<std::shared_ptr<const Result>> &results);

	/// Primary ctor
	explicit CountFailure(const std::shared_ptr<const Result> &result);

	/// Get count of failures
	size_t count() const;
private:
	const std::shared_ptr<const Result> result;
};

}
