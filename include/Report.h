// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <map>
#include <string>

namespace oout {

// @todo #46:15min Add RepJUnit for xml output
class Report {
public:
	virtual ~Report() = default;
	virtual void begin(
		const std::string &tag,
		const std::map<std::string, std::string> &attributes
	) = 0;
	virtual void end(const std::string &tag) = 0;
};

}
