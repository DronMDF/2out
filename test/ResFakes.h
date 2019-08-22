// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <2out/Result.h>

// @todo #356 All ResFakes should be renamed to BlablablaResult by naming convention

class ResOkCase final : public oout::Result {
public:
	explicit ResOkCase(const std::string &name = "");
	std::string print(const oout::Format &format) const override;
private:
	const std::string name;
};

class ResFailureCase final : public oout::Result {
public:
	explicit ResFailureCase(const std::string &name = "");
	std::string print(const oout::Format &format) const override;
private:
	const std::string name;
};

class ResErrorCase final : public oout::Result {
public:
	explicit ResErrorCase(const std::string &name = "");
	std::string print(const oout::Format &format) const override;
private:
	const std::string name;
};

