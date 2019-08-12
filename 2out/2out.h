// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once

// Core
#include "Result.h"

// Report formatters
#include "TextReport.h"
#include "JUnitXmlReport.h"

// Result statistics
#include "CountError.h"
#include "CountFailure.h"
#include "CountTest.h"

// Text
#include "Text.h"
#include "ReprCallable.h"
#include "ReprPrintable.h"
#include "ReprSigned.h"
#include "ReprString.h"

// Tests
#include "ContainTest.h"
#include "EndsWithTest.h"
#include "EqualTest.h"
#include "MatchTest.h"
#include "NamedTest.h"
#include "SafeTest.h"
#include "SkippedTest.h"
#include "StartsWithTest.h"
#include "SuiteTest.h"
#include "TimedTest.h"

// Matches
#include "AllMatch.h"
#include "ContainMatch.h"
#include "EndsWithMatch.h"
#include "EqualMatch.h"
#include "RegexMatch.h"
#include "StartsWithMatch.h"

// Deprecated (since 0.7)
#include "Representation.h"
#include "TestContainText.h"
#include "TestEndsWith.h"
#include "TestEqual.h"
#include "TestNamed.h"
#include "TestSafe.h"
#include "TestSkipped.h"
#include "TestStartsWith.h"
#include "TestSuite.h"
#include "TestTimed.h"
