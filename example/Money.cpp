// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Money.h"

using namespace std;

Money::Money(int amount, const string &currency)
	: _amount(amount), _currency(currency)
{
}

int Money::amount() const
{
	return _amount;
}

string Money::currency() const
{
	return _currency;
}
