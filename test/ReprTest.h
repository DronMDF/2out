// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <memory>
#include <2out/Representation.h>
#include <2out/Test.h>

// @todo #322 ReprTest should be renamed
//  In current naming - TestRepr,
//  But i want to change Representation to Text

class ReprTest final : public oout::Representation {
public:
	explicit ReprTest(const std::shared_ptr<const oout::Test> &test);
	std::string asString() const override;
private:
	const std::shared_ptr<const oout::Test> test;
};
