// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <string>

class Bank final {
public:
	Bank(const std::string &source, const std::string &to, int rate);

	int getRate(const std::string &source, const std::string &to) const;
private:
	const std::string source;
	const std::string to;
	int rate;
};
