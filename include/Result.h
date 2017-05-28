// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once

namespace oout {

class Result {
public:
	virtual ~Result() = default;
	virtual bool status() const = 0;
};

}
