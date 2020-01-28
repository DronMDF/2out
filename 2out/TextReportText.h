// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <string>
#include "Text.h"

namespace oout {

class Result;

/// Text Report like google test
class TextReportText final : public Text {
public:
	/// Primary ctor
	explicit TextReportText(const std::shared_ptr<const Result> &result);

	/// Get report as string
	std::string asString() const override;
private:
	const std::shared_ptr<const Result> result;
};

}
