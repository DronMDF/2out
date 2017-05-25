// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <string>

namespace oout {

class Test;

class TextReport final {
public:
	explicit TextReport(std::unique_ptr<const Test> test);
	std::string asString() const;
private:
	const std::unique_ptr<const Test> test;
};

}
