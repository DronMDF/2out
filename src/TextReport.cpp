// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TextReport.h>
#include <iostream>
#include <Result.h>
#include <Test.h>

using namespace std;
using namespace oout;

TextReport::TextReport()
	: text()
{
}

void TextReport::begin(const string &tag, const map<string, string> &attributes)
{
	text << tag << ": ";
	for (const auto &ap : attributes) {
		text << ap.first << "='" << ap.second << "' ";
	}
	text << endl;
}

void TextReport::end(const std::string &)
{
}

string TextReport::asString() const
{
	return text.str();
}
