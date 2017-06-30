// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>

namespace oout {

class Result;

class CountTest final {
public:
	explicit CountTest(const std::list<std::shared_ptr<const Result>> &results);
	explicit CountTest(const std::shared_ptr<const Result> &result);

	size_t count() const;
private:
	const std::shared_ptr<const Result> result;
};

}
