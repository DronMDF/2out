// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Money.h"

class Bank;

class ExchangedMoney final : public Money {
public:
	ExchangedMoney(
		const std::shared_ptr<const Money> &money,
		int rate,
		const std::string &currency
	);
	ExchangedMoney(
		const std::shared_ptr<const Money> &money,
		const std::shared_ptr<const Bank> &bank,
		const std::string &currency
	);
	int amount() const override;
	std::string currency() const override;
private:
	const std::shared_ptr<const Money> money;
	const int rate;
	const std::string _currency;
};
