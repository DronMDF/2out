// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Money.h"

class TimesMoney final : public Money {
public:
	TimesMoney(const std::shared_ptr<const Money> &money, int multiplier);
	int amount() const override;
	std::string currency() const override;
private:
	const std::shared_ptr<const Money> money;
	int multiplier;
};
