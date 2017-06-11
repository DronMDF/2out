// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <string>

namespace oout {

class Result;

class JUnitXmlReport final {
public:
	explicit JUnitXmlReport(const std::shared_ptr<const Result> &result);
	std::string asString() const;
private:
	const std::shared_ptr<const Result> result;
};

}