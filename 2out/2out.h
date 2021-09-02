// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once

// Core
#include "Result.h"

// Tests
#include "MatchTest.h"
#include "NamedTest.h"
#include "SafeTest.h"
#include "SkippedTest.h"
#include "SuiteTest.h"
#include "TimedTest.h"

// Matches
#include "AllMatch.h"
#include "ContainMatch.h"
#include "EndsWithMatch.h"
#include "EqualMatch.h"
#include "RegexMatch.h"
#include "StartsWithMatch.h"

// Text
#include "CtorExceptionText.h"
#include "FunctionText.h"
#include "MethodExceptionText.h"
#include "OoutReportText.h"
#include "PrintableText.h"
#include "SignedText.h"
#include "StringText.h"
#include "GtestReportText.h"
#include "XmlReportText.h"

// Misc
#include "CountError.h"
#include "CountFailure.h"
#include "CountTest.h"

// Deprecated (will be removed in 0.11)
#include "ContainTest.h"
#include "EndsWithTest.h"
#include "EqualTest.h"
#include "RegexTest.h"
#include "StartsWithTest.h"
