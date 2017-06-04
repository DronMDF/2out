// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <Result.h>

class ResFailureCase final : public oout::Result {
public:
	explicit ResFailureCase(const std::string &name = "");
	std::string print(const oout::Format &format) const override;
private:
	const std::string name;
};

class ResOkCase final : public oout::Result {
public:
	explicit ResOkCase(const std::string &name = "");
	std::string print(const oout::Format &format) const override;
private:
	const std::string name;
};
