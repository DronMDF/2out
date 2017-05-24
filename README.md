# 2out

Object oriented unit testing framework

# Concept

This is a pseudocode (i think this is a eolang :))

```
object TestApp as Application:
	void run():
		TstSuite:
			"main",
			TstSimple:
				"2*2 should be equal 4",
				IsEqual:
					mul: 2, 2
					4
			TstSkipped:
				"Temporary off, failed",
				TstSimple:
					"2*2 should be equal 5",
					IsEqual:
						mul: 2, 2
						5
			TstSuite:
				"plus",
				TstSimple:
					"2+2 should be equal 4",
					IsEqual:
						plus: 2, 2
						4
				TstSimple:
					"3+3 should be equal 6",
					IsEqual:
						plus: 3, 3
						6
		.run()
```

Key moment - Assertion (IsEqual) this is an object.
Each test should have only one assertion. We throw out code and describe all tests over Object composition.
This helped to avoid the problem of lost tests. Test invocation is a Test text itself.

# Dictionary

## Test

This is a test.
TstSimple, TstSuite, TstSkipped - is an object of Test type.

## Assertion

Test framework has a standard set of asserions (IsEqual, In, Except, etc...)
You can add your own assertions.
This is the only time when we write something for testing.
Assertion shoud be lazy Objects.
All args of assertion should be lazy too.

# Questions

1. Describe all tests in one place - is bad. But if you describe the tests elsewhere, the problem of lost sets is possible.
1. Test shuffling is hard...
1. Need to thinking about different format of report.
1. Test naming and filtering... May be test should have 3 parameters? name, description and assertion?
