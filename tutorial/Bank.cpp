// Copyright (c) 2017-2021 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "Bank.h"
#include <stdexcept>

using namespace std;

Bank::Bank(const string &source, const string &to, int rate)
	: source(source), to(to), rate(rate)
{
}

int Bank::getRate(const string &src, const string &dst) const
{
	if (src == dst) {
		return 1;
	}
	if (src != source || dst != to) {
		throw runtime_error("Unknown rate");
	}
	return rate;
}
