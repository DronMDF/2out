// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TextReport.h>
#include <Result.h>
#include <Test.h>

using namespace std;
using namespace oout;

TextReport::TextReport(const shared_ptr<const Result> &result)
	: result(result)
{
}

string TextReport::asString() const
{
	return result->status() ? "SUCCESS" : "FAILURE";
}
