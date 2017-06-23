// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <sstream>
#include "StringRepr.h"
#include "Test.h"

namespace oout {

template<typename V>
class AnyRepr final : public StringRepr {
public:
	explicit AnyRepr(const V &value)
		: value(value)
	{
	}

	std::string asString() const override {
		std::ostringstream out;
		out << value;
		return out.str();
	}

private:
	const V value;
};

class TestEqual final : public Test {
public:
	template<typename A, typename B>
	TestEqual(const A &a, const B &b)
		: a(std::make_shared<AnyRepr<A>>(a)),
		  b(std::make_shared<AnyRepr<B>>(b))
	{
	}

	template<typename B>
	TestEqual(const std::shared_ptr<const StringRepr> &a, const B &b)
		: a(a), b(std::make_shared<AnyRepr<B>>(b))
	{
	}

	TestEqual(
		const std::shared_ptr<const StringRepr> &a,
		const std::shared_ptr<const StringRepr> &b
	);

	std::shared_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const StringRepr> a;
	const std::shared_ptr<const StringRepr> b;
};

}

