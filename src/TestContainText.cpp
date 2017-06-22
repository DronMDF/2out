// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TestContainText.h>
#include <AssertionResult.h>
#include <Failure.h>
#include <ResSimple.h>
#include <Success.h>

using namespace std;
using namespace oout;

TestContainText::TestContainText(const shared_ptr<const StringRepr> &repr, const string &text)
	: repr(repr), text(text)
{
}

// @todo #152:15min Need to introduce TestSafe decorator.
//  This decorator catch all exceptions and form Error Result.
shared_ptr<const Result> TestContainText::result() const
{
	shared_ptr<const AssertionResult> assertion_result;
	if (repr->asString().find(text) != string::npos) {
		assertion_result = make_shared<Success>();
	} else {
		assertion_result = make_shared<Failure>();
	}
	// @todo #152:15min Need to generate auto name for test.
	return make_shared<const ResSimple>("", assertion_result);
};
