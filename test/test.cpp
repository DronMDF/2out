// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <list>
#include <memory>
#include <2out/2out.h>
#include "CondResultTest.h"
#include "ContainMatchTest.h"
#include "ContainTestTest.h"
#include "CountErrorTest.h"
#include "CountFailureTest.h"
#include "CountTestTest.h"
#include "CtorExceptionTextTest.h"
#include "DirtyTestTest.h"
#include "EndsWithMatchTest.h"
#include "EndsWithTestTest.h"
#include "FunctionTextTest.h"
#include "MatchTestTest.h"
#include "NamedTestTest.h"
#include "PrintableTextTest.h"
#include "RegexMatchTest.h"
#include "RegexTestTest.h"
#include "SkippedTestTest.h"
#include "StartsWithMatchTest.h"
#include "StartsWithTestTest.h"
#include "SuiteTestTest.h"
#include "TextReportTextTest.h"
#include "XmlReportTextTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const SuiteTest tests(
		make_shared<CondResultTest>(),
		make_shared<ContainMatchTest>(),
		make_shared<ContainTestTest>(),
		make_shared<CountErrorTest>(),
		make_shared<CountFailureTest>(),
		make_shared<CountTestTest>(),
		make_shared<CtorExceptionTextTest>(),
		make_shared<DirtyTestTest>(),
		make_shared<EndsWithMatchTest>(),
		make_shared<EndsWithTestTest>(),
		make_shared<FunctionTextTest>(),
		make_shared<MatchTestTest>(),
		make_shared<NamedTestTest>(),
		make_shared<PrintableTextTest>(),
		make_shared<RegexMatchTest>(),
		make_shared<RegexTestTest>(),
		make_shared<SkippedTestTest>(),
		make_shared<StartsWithMatchTest>(),
		make_shared<StartsWithTestTest>(),
		make_shared<SuiteTestTest>(),
		make_shared<TextReportTextTest>(),
		make_shared<XmlReportTextTest>()
	);

	const shared_ptr<const Result> result = tests.result();

	cout << XmlReportText(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
