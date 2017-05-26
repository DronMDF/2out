// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <Test.h>

class TstSuiteTest final : public oout::Test
{
public:
	TstSuiteTest();
	bool result() const override;

private:
	const std::unique_ptr<const oout::Test> tests;
};
