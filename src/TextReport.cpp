// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TextReport.h>
#include <Test.h>

using namespace std;
using namespace oout;

TextReport::TextReport(unique_ptr<const Test> test)
	: test(move(test))
{
}

string TextReport::asString() const
{
	return test->result() ? "SUCCESS" : "FAILURE";
}
