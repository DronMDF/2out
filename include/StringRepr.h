// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>

namespace oout {

// @todo #151:15min Need to introduce generic StringRepr for any type.
//  This repr can use ostringstream for stringize object

// @todo #151:15min Need to introduce StringRepr for string type.
//  I mean StringRepr is good name. string_view is a standart class.

class StringRepr {
public:
	virtual ~StringRepr() = default;
	virtual std::string asString() const = 0;
};

}
