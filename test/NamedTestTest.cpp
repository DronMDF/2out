// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "NamedTestTest.h"
#include <2out/2out.h>
#include "TestText.h"

using namespace std;
using namespace oout;

class NamedTestText final : public Text {
public:
	explicit NamedTestText(const shared_ptr<const Test> &test)
		: test(test)
	{
	}

	string asString() const override
	{
		return XmlReportText(test->result()).asString();
	}
private:
	const shared_ptr<const Test> test;
};

NamedTestTest::NamedTestTest()
: dirty::Test(
	"NamedTest test",
	make_shared<NamedTest>(
		"NamedTest in NamedTest is a Suite",
		make_shared<MatchTest>(
			make_shared<NamedTestText>(
				make_unique<NamedTest>(
					"Root test",
					make_shared<const NamedTest>(
						"Concrete test",
						make_shared<EqualTest>("a", "a")
					)
				)
			),
			make_shared<ContainMatch>("Concrete test")
		)
	),
	make_shared<NamedTest>(
		"NamedTest make MatchTest if third arg is match (this is selftest)",
		make_shared<NamedTestText>(
			make_unique<NamedTest>(
				"Match test",
				make_shared<EqualTest>("a", "a")
			)
		),
		make_shared<ContainMatch>("Match test")
	)
)
{
}
