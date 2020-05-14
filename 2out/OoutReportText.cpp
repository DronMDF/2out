// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "OoutReportText.h"
#include <sstream>
#include "CountError.h"
#include "CountFailure.h"
#include "CountTest.h"
#include "OoutFormat.h"
#include "Result.h"

using namespace std;
using namespace oout;

OoutReportText::OoutReportText(const shared_ptr<const Result> &result)
	: result(result)
{
}

string OoutReportText::asString() const
{
	ostringstream out;
	out << result->print(OoutFormat());
	out << (CountFailure(result).count() + CountError(result).count())
		<< " of " << CountTest(result).count() << " tests failed";
	return out.str();
}
