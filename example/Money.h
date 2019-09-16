// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>

class Money final {
public:
	Money(int amount, const std::string &currency);
	int amount() const;
	std::string currency() const;
private:
	const int _amount;
	const std::string _currency;
};
