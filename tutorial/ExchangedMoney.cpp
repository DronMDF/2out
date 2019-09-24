// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "ExchangedMoney.h"
#include "Bank.h"

using namespace std;

ExchangedMoney::ExchangedMoney(
	const shared_ptr<const Money> &money,
	int rate,
	const string &currency
) : money(money), rate(rate), _currency(currency)
{
}

ExchangedMoney::ExchangedMoney(
	const shared_ptr<const Money> &money,
	const shared_ptr<const Bank> &bank,
	const string &currency
) : ExchangedMoney(money, bank->getRate(money->currency(), currency), currency)
{
}

int ExchangedMoney::amount() const
{
	return money->amount() / rate;
}

string ExchangedMoney::currency() const
{
	return _currency;
}
