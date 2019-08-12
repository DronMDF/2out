// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Test.h"
#include "AllMatch.h"

namespace oout {

class Match;
class Text;

class MatchTest final : public Test {
public:
	/// Primary ctor
	MatchTest(
		const std::shared_ptr<const Text> &text,
		const std::shared_ptr<const Match> &match
	);

	template<typename... T>
	MatchTest(
		const std::shared_ptr<const Text> &text,
		const std::shared_ptr<const Match> &match1,
		const std::shared_ptr<const Match> &match2,
		const std::shared_ptr<T> & ... matchn
	) : MatchTest(text, std::make_shared<AllMatch>(match1, match2, matchn...))
	{
	}

	/// Get test result
	std::unique_ptr<const Result> result() const override;

private:
	const std::shared_ptr<const Text> text;
	const std::shared_ptr<const Match> match;
};

}
