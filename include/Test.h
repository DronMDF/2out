// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once

namespace oout {

class Test {
public:
	// @todo #30:15min Test Result should contain more information
	//  Test name, checked assertion details, status, time, and more
	//  In Suite case Result should contain information about subtests
	virtual bool result() const = 0;
};

}
