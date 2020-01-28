// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CtorExceptionTextTest.h"
#include <2out/2out.h>

using namespace std;
using namespace oout;

class WithException {
public:
	explicit WithException(const string &message)
	{
		throw runtime_error(message);
	}

	WithException()
		: WithException("shit happen")
	{
	}
};

CtorExceptionTextTest::CtorExceptionTextTest()
: dirty::Test(
	"Exception in ctor represent as a text",
	make_shared<const NamedTest>(
		"CtorExceptionText is a exception message",
		make_shared<CtorExceptionText<WithException>>(),
		make_shared<EqualMatch>("shit happen")
	),
	make_shared<const NamedTest>(
		"CtorExceptionText pass args to CUT ctor",
		make_shared<CtorExceptionText<WithException>>("argument"),
		make_shared<EqualMatch>("argument")
	)
)
{
}
