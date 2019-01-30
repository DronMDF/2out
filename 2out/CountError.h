// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>

namespace oout {

class Result;

/// Number of errors in test results
class CountError final {
public:
	/// Secondary ctor from list of results
	explicit CountError(const std::list<std::shared_ptr<const Result>> &results);
	/// Primary ctor from composite result
	explicit CountError(const std::shared_ptr<const Result> &result);

	/// Number of errors
	size_t count() const;
private:
	const std::shared_ptr<const Result> result;
};

}
