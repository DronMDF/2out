// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "OrderItemMoney.h"
#include "Money.h"

using namespace std;

OrderItemMoney::OrderItemMoney(const shared_ptr<const Money> &money, int quantity)
	: money(money), quantity(quantity)
{
}

int OrderItemMoney::amount() const
{
	return money->amount() * quantity;
}

string OrderItemMoney::currency() const
{
	return money->currency();
}
