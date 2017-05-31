// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <sstream>
#include <string>
#include "Report.h"

namespace oout {

class Result;

class TextReport final : public Report {
public:
	TextReport();

	void begin(
		const std::string &tag,
		const std::map<std::string, std::string> &attributes
	) override;
	void end(const std::string &tag) override;

	std::string asString() const;
private:
	std::ostringstream text;
};

}
