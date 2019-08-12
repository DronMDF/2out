// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Match.h"
#include <vector>

namespace oout {

class AllMatch final : public Match {
public:
	/// Primary ctor
	explicit AllMatch(const std::vector<std::shared_ptr<const Match>> &matches);

	/// Secondary ctor from matches
	template<typename... T>
	explicit AllMatch(
		const std::shared_ptr<const Match> &match1,
		const std::shared_ptr<T> & ... matches
	) : AllMatch(std::vector<std::shared_ptr<const Match>>{
		match1, matches...
	    })
	{
	}

	std::unique_ptr<const Result> match(
		const std::shared_ptr<const Text> &in
	) const override;

private:
	const std::vector<std::shared_ptr<const Match>> matches;
};

}
