// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <cstddef>

namespace oout {

// @todo #41:15min Result should be like a xml node.
//  Should have immutable possibility for add attributes or subnodes.
//  And printed out.
class Result {
public:
	virtual ~Result() = default;
	virtual size_t failures() const = 0;
};

}
