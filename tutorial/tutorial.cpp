// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <2out/2out.h>
#include "Bank.h"
#include "MoneyText.h"
#include "OrderItemMoney.h"
#include "OrderMoney.h"
#include "RealMoney.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const SuiteTest tests{
		make_shared<EqualTest>(
			make_shared<MoneyText>(
				make_shared<RealMoney>(5, "USD")
			),
			"5 USD"
		),
		make_shared<NamedTest>(
			"$5 * 2 = $10",
			make_shared<EqualTest>(
				make_shared<MoneyText>(
					make_shared<OrderItemMoney>(
						make_shared<RealMoney>(5, "USD"),
						2
					)
				),
				"10 USD"
			)
		),
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
	};
	const shared_ptr<const Result> result = tests.result();

	cout << TextReportText(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
