// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>

namespace oout {

class Result;

/// Number of test results
class CountTest final {
public:
	/// Secondary ctor from list of results
	explicit CountTest(const std::list<std::shared_ptr<const Result>> &results);
	/// Prinary ctor from composite result
	explicit CountTest(const std::shared_ptr<const Result> &result);

	/// Number of tests results
	size_t count() const;
private:
	const std::shared_ptr<const Result> result;
};

}
