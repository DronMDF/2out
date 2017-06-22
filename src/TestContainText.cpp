// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TestContainText.h>
#include <algorithm>
#include <sstream>
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

	// @todo #159:15min Convert object text to name part - this is common operation.
	//  Need to extract this entity. Special object should produce short and nice pard of text.
	ostringstream name_stream;
	name_stream << text << " in " << repr->asString().substr(0, 16);

	// @todo #159:15min Filtering of name actual only for special representations
	//  like an xml or json...
	const auto raw_name = name_stream.str();
	string name;
	remove_copy_if(raw_name.begin(), raw_name.end(), back_inserter(name),
		[](const string::value_type &c){
			return string("<>'").find(c) != string::npos;
		}
	);

	return make_shared<const ResSimple>(name, assertion_result);
};
