// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>

class Money {
public:
	virtual ~Money() = default;
	virtual int amount() const = 0;
	virtual std::string currency() const = 0;
};
