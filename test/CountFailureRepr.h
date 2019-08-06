// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Representation.h>

namespace oout { class CountFailure; }

class CountFailureRepr final : public oout::Representation {
public:
	explicit CountFailureRepr(const std::shared_ptr<const oout::CountFailure> &count);
	std::string asString() const override;
private:
	const std::shared_ptr<const oout::CountFailure> count;
};
