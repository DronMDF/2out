// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "MethodExceptionTextTest.h"
#include <2out/2out.h>

using namespace std;
using namespace oout;

class WithExceptionInMethod {
public:
	void failure(const string &message) const
	{
		throw runtime_error(message);
	}
};

MethodExceptionTextTest::MethodExceptionTextTest()
: dirty::Test(
	"Exception in method represent as a text",
	make_shared<const NamedTest>(
		"MethodExceptionText catch exception as a text",
		make_shared<MethodExceptionText>(
			&WithExceptionInMethod::failure,
			make_shared<WithExceptionInMethod>(),
			"no fate"
		),
		make_shared<EqualMatch>("no fate")
	)
)
{
}
