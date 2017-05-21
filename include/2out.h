#pragma once
#include <list>
#include <memory>
#include <string>

namespace oout {

class Assertion {
};

class Case {
public:
	Case(const std::string &description, std::unique_ptr<const Assertion> assert)
	{
	}
};

class Suite {
public:
	Suite(const std::string &description, const std::list<std::shared_ptr<const Case>> &cases)
	{
	}

	int run() const
	{
		return 0;
	}
};

class AssertionEqual final : public Assertion {
public:
	AssertionEqual(int a, int b)
	{
	}
};

}
