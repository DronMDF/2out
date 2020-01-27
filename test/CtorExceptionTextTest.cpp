// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "CtorExceptionTextTest.h"
#include <2out/2out.h>
#include "TestText.h"

using namespace std;
using namespace oout;

class WithException {
public:
	WithException() {
		throw runtime_error("shit happen");
	}
};

CtorExceptionTextTest::CtorExceptionTextTest()
: dirty::Test(
	"Exception in ctor represent as a text",
	make_shared<const NamedTest>(
		"CtorExceptionText is a exception message",
		make_shared<CtorExceptionText<WithException>>(),
		make_shared<EqualMatch>("shit happen")
	)
)
{
}
