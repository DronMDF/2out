// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "OrderMoneyTest.h"
#include <2out/2out.h>
#include "Bank.h"
#include "MoneyText.h"
#include "OrderMoney.h"
#include "RealMoney.h"

using namespace std;
using namespace oout;

OrderMoneyTest::OrderMoneyTest()
: dirty::Test(
	"OrderMoney tests",
	make_shared<NamedTest>(
		"OrderMoney is sum of all items",
		make_shared<EqualTest>(
			make_shared<MoneyText>(
				make_shared<OrderMoney>(
					make_shared<RealMoney>(5, "USD"),
					make_shared<RealMoney>(7, "USD")
				)
			),
			"12 USD"
		)
	),
	make_shared<NamedTest>(
		"OrderMoney is sum of one items",
		make_shared<EqualTest>(
			make_shared<MoneyText>(
				make_shared<OrderMoney>(
					make_shared<RealMoney>(42, "USD")
				)
			),
			"42 USD"
		)
	),
	make_shared<NamedTest>(
		"OrderMoney is sum of three items",
		make_shared<EqualTest>(
			make_shared<MoneyText>(
				make_shared<OrderMoney>(
					make_shared<RealMoney>(1, "USD"),
					make_shared<RealMoney>(2, "USD"),
					make_shared<RealMoney>(4, "USD")
				)
			),
			"7 USD"
		)
	),
	make_shared<NamedTest>(
		"OrderMoney is unify all money over Bank",
		make_shared<EqualTest>(
			make_shared<MoneyText>(
				make_shared<OrderMoney>(
					"USD",
					make_shared<Bank>("CHF", "USD", 2),
					make_shared<RealMoney>(5, "USD"),
					make_shared<RealMoney>(10, "CHF")
				)
			),
			"10 USD"
		)
	)
)
{
}
