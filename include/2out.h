// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <list>
#include <memory>
#include <string>
#include "Assertion.h"
#include "Test.h"

namespace oout {

// @todo #8:15min Move TstSimple to TstSimple.cpp
class TstSimple final : public Test {
public:
	TstSimple(const std::string &description, std::unique_ptr<const Assertion> assert)
		: assert(move(assert))
	{
	}

	bool result() const override
	{
		return assert->valid();
	}

private:
	std::unique_ptr<const Assertion> assert;
};

// @todo #8:15min Move TstSuite to TstSuite.cpp
class TstSuite final : public Test {
public:
	TstSuite(
		const std::string &description,
		const std::list<std::shared_ptr<const Test>> &cases
	) : cases(cases)
	{
	}

	bool result() const override
	{
		for (const auto &c : cases) {
			if (!c->result()) {
				return false;
			}
		}
		return true;
	}

private:
	const std::list<std::shared_ptr<const Test>> cases;
};

// @todo #8:15min Move AssertionEqual to AsEqual.cpp
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
