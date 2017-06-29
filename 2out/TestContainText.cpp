// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TestContainText.h>
#include <algorithm>
#include <sstream>
#include <AssertionResult.h>
#include <Failure.h>
#include <ReprString.h>
#include <ResSimple.h>
#include <Success.h>

using namespace std;
using namespace oout;

TestContainText::TestContainText(const string &text, const string &substr)
	: TestContainText(make_shared<ReprString>(text), make_shared<ReprString>(substr))
{
}

TestContainText::TestContainText(const string &text, const shared_ptr<const Representation> &substr)
	: TestContainText(make_shared<ReprString>(text), substr)
{
}

TestContainText::TestContainText(const shared_ptr<const Representation> &text, const string &substr)
	: TestContainText(text, make_shared<ReprString>(substr))
{
}

TestContainText::TestContainText(
	const shared_ptr<const Representation> &text,
	const shared_ptr<const Representation> &substr
) : text(text), substr(substr)
{
}

shared_ptr<const Result> TestContainText::result() const
{
	ostringstream test_text;
	test_text << "'" << substr->asString() << "' in '" << text->asString() << "'";

	shared_ptr<const AssertionResult> assertion_result;
	if (text->asString().find(substr->asString()) != string::npos) {
		assertion_result = make_shared<Success>(test_text.str());
	} else {
		assertion_result = make_shared<Failure>(test_text.str());
	}
	return make_shared<const ResSimple>(assertion_result);
}