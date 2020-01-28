// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "AllMatch.h"
#include "ContainMatch.h"
#include "StringText.h"
#include "Test.h"
#include "Text.h"

namespace oout {

/// Test for substring present in string
class ContainTest final : public Test {
private:
	/// Primary ctor
	ContainTest(
		const std::shared_ptr<const Text> &text,
		const std::shared_ptr<const Match> &match
	);

	template<typename ... T>
	ContainTest(
		const std::shared_ptr<const Text> &text,
		const std::shared_ptr<const Match> &match1,
		const std::shared_ptr<const Match> &match2,
		const std::shared_ptr<T> & ... matchn
	) : ContainTest(text, std::make_shared<AllMatch>(match1, match2, matchn...))
	{
	}

public:
	// Multiple ctor with strings
	template<typename ... S>
	ContainTest(
		const std::shared_ptr<const Text> &text,
		const std::string &sub,
		S ... subs
	) : ContainTest(text, subs..., std::make_shared<ContainMatch>(sub))
	{
	}

	/// Secondary ctor from strings
	template<typename ... S>
	ContainTest(
		const std::string &text,
		S ... subs
	) : ContainTest(std::make_shared<StringText>(text), subs...)
	{
	}

	/// Test result
	std::unique_ptr<const Result> result() const override;

private:
	const std::shared_ptr<const Test> test;
};

}
