// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TimesMoney.h"
#include "Money.h"

using namespace std;

TimesMoney::TimesMoney(const shared_ptr<const Money> &money, int multiplier)
	: money(money), multiplier(multiplier)
{
}

int TimesMoney::amount() const
{
	return money->amount() * multiplier;
}

string TimesMoney::currency() const
{
	return money->currency();
}
