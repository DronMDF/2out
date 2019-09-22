// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "OrderMoney.h"
#include "RealMoney.h"

using namespace std;

OrderMoney::OrderMoney(const shared_ptr<const Money> &a, const shared_ptr<const Money> &b)
	: a(a), b(b)
{
}

OrderMoney::OrderMoney(const shared_ptr<const Money> &a)
	: a(a), b(make_shared<RealMoney>(0, a->currency()))
{
}

int OrderMoney::amount() const
{
	if (a->currency() != b->currency()) {
		throw runtime_error("Multicurrency operations without convert");
	}
	return a->amount() + b->amount();
}

string OrderMoney::currency() const
{
	if (a->currency() != b->currency()) {
		throw runtime_error("Multicurrency operations without convert");
	}
	return a->currency();
}
