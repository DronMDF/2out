// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>
#include <string>

namespace oout {

class Assertion {
public:
	virtual bool valid() const = 0;
};

class Case {
public:
	Case(const std::string &description, std::unique_ptr<const Assertion> assert)
		: assert(move(assert))
	{
	}

	bool run() const
	{
		return assert->valid();
	}

private:
	std::unique_ptr<const Assertion> assert;
};

class Suite {
public:
	Suite(const std::string &description, const std::list<std::shared_ptr<const Case>> &cases)
		: cases(cases)
	{
	}

	bool run() const
	{
		for (const auto &c : cases) {
			if (!c->run()) {
				return false;
			}
		}
		return true;
	}

private:
	const std::list<std::shared_ptr<const Case>> cases;
};

class AssertionEqual final : public Assertion {
public:
	AssertionEqual(int a, int b)
		: a(a), b(b)
	{
	}

	bool valid() const override
	{
		return a == b;
	}

private:
	int a;
	int b;
};

}
