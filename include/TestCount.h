// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>

namespace oout {

class Result;

// @todo #152:15min TestCount is name, conflicted with Test* implementations.
//  This representation should be name like CountOfTests..
class TestCount final {
public:
	explicit TestCount(const std::list<std::shared_ptr<const Result>> &results);
	explicit TestCount(const std::shared_ptr<const Result> &result);

	size_t count() const;
private:
	const std::shared_ptr<const Result> result;
};

}
