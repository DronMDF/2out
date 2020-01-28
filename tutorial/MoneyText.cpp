// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MoneyText.h"
#include "Money.h"

using namespace std;

MoneyText::MoneyText(const shared_ptr<const Money> &money)
	: money(money)
{
}

string MoneyText::asString() const
{
	return to_string(money->amount()) + " " + money->currency();
}
