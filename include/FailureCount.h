// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

namespace oout {

class Result;

class FailureCount final {
public:
	explicit FailureCount(const std::shared_ptr<const Result> &result);

	size_t count() const;
private:
	const std::shared_ptr<const Result> result;
};

}

