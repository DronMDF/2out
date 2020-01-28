// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "ExchangedMoney.h"
#include "Money.h"

class Bank;

class OrderMoney final : public Money {
public:
	OrderMoney(const std::shared_ptr<const Money> &a, const std::shared_ptr<const Money> &b);
	explicit OrderMoney(const std::shared_ptr<const Money> &a);

	template <typename ... T>
	OrderMoney(
		const std::shared_ptr<const Money> &a,
		const std::shared_ptr<const Money> &b,
		const std::shared_ptr<const Money> &c,
		const T & ...d
	) : OrderMoney(std::make_shared<OrderMoney>(a, b), c, d...)
	{
	}

	template <typename ... T>
	OrderMoney(
		const std::string &currency,
		const std::shared_ptr<const Bank> &bank,
		const T & ... money
	) : OrderMoney(std::make_shared<ExchangedMoney>(money, bank, currency)...)
	{
	}

	int amount() const override;
	std::string currency() const override;

private:
	const std::shared_ptr<const Money> a;
	const std::shared_ptr<const Money> b;
};
