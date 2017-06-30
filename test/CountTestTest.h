// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <Test.h>

class CountTestTest final : public oout::Test {
public:
	CountTestTest();
	std::shared_ptr<const oout::Result> result() const override;
private:
	const std::unique_ptr<const oout::Test> tests;
};
