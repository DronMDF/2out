// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <2out/2out.h>

using namespace std;
using namespace oout;

int main(int, char **)
{
	const EqualTest test("2out", "2out");
	const shared_ptr<const Result> result = test.result();

	cout << OoutReportText(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
