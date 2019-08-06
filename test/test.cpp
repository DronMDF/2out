// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <list>
#include <memory>
#include <2out/2out.h>
#include "ContainMatchTest.h"
#include "ContainTestTest.h"
#include "CondResultTest.h"
#include "CountErrorTest.h"
#include "CountFailureTest.h"
#include "CountTestTest.h"
#include "DirtyTestTest.h"
#include "EndsWithTestTest.h"
#include "JUnitXmlReportTest.h"
#include "MatchTestTest.h"
#include "NamedTestTest.h"
#include "ReprCallableTest.h"
#include "ReprPrintableTest.h"
#include "SkippedTestTest.h"
#include "StartsWithMatchTest.h"
#include "StartsWithTestTest.h"
#include "SuiteTestTest.h"
#include "TextReportTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const SuiteTest tests(
		make_shared<ContainMatchTest>(),
		make_shared<ContainTestTest>(),
		make_shared<CondResultTest>(),
		make_shared<CountErrorTest>(),
		make_shared<CountFailureTest>(),
		make_shared<CountTestTest>(),
		make_shared<DirtyTestTest>(),
		make_shared<EndsWithTestTest>(),
		make_shared<JUnitXmlReportTest>(),
		make_shared<MatchTestTest>(),
		make_shared<NamedTestTest>(),
		make_shared<ReprCallableTest>(),
		make_shared<ReprPrintableTest>(),
		make_shared<SkippedTestTest>(),
		make_shared<StartsWithMatchTest>(),
		make_shared<StartsWithTestTest>(),
		make_shared<SuiteTestTest>(),
		make_shared<TextReportTest>()
	);

	const shared_ptr<const Result> result = tests.result();

	cout << JUnitXmlReport(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
