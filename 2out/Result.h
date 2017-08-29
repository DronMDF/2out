// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>

namespace oout {

class Format;

/// Abstract test result
class Result {
public:
	/// Virtual dtor
	virtual ~Result() = default;

	/// Printer
	virtual std::string print(const Format &format) const = 0;
};

}
