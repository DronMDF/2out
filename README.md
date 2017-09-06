# 2out

Object oriented unit testing framework

[![Shippable](https://api.shippable.com/projects/5922a40c2a28350700f84ee0/badge?branch=master)](https://app.shippable.com/github/DronMDF/2out/status/dashboard)
[![Travis](https://travis-ci.org/DronMDF/2out.svg?branch=master)](https://travis-ci.org/DronMDF/2out)
[![CircleCI](https://circleci.com/gh/DronMDF/2out.svg?style=shield)](https://circleci.com/gh/DronMDF/2out)
[![codecov](https://codecov.io/gh/DronMDF/2out/branch/master/graph/badge.svg)](https://codecov.io/gh/DronMDF/2out)
[![PDD status](http://www.0pdd.com/svg?name=DronMDF/2out)](http://www.0pdd.com/p?name=DronMDF/2out)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/DronMDF/2out/blob/master/LICENSE)

# Intro

The test framework does not should be easy to use.
The test framework should help to do everything right.
And after that it should be easy to use. :)

# Concept

This is a pseudocode (i think this is a eolang :))

```
object TestApp as Application:
	void run():
		TestSuite:
			TestEqual:
				mul: 2, 2
				4
			TestSkipped:
				TestEqual:
					mul: 2, 2
					5
			TestNamed:
				"3 * 3 should be equal 9"
				TestEqual:
					mul: 3, 3
					9
			TestSuite:
				TestEqual:
					plus: 2, 2
					4
				TestSafe:
					TestEqual:
						div: 1, 0
						100500
		.run()
```

Key moment: This is not a code. This is Object composition.
At the time the composition is created, the tests do not start.
Tests start in `run()` method.
