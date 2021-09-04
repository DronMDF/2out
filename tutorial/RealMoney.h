// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Money.h"

class RealMoney final : public Money {
public:
	RealMoney(int amount, const std::string &currency);
	int amount() const override;
	std::string currency() const override;
private:
	const int _amount;
	const std::string _currency;
};
