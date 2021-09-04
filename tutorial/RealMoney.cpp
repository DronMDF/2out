// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "RealMoney.h"

using namespace std;

RealMoney::RealMoney(int amount, const string &currency)
	: _amount(amount), _currency(currency)
{
}

int RealMoney::amount() const
{
	return _amount;
}

string RealMoney::currency() const
{
	return _currency;
}
