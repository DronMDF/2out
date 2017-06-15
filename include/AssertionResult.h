// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once

namespace oout {

// @todo #103:15min AssertionResult should be printed
//  It visualize as failures or success details
class AssertionResult final {
public:
	explicit AssertionResult(bool success);
	operator bool() const;
private:
	bool success;
};

}
