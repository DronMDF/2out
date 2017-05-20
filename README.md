# 2out
Object oriented unit testing framework

# Concept

This is a pseudocode (i think this is a eolang :))

```
object TestApp as Application:
	void run():
		Suite:
			"main",
			Case:
				"2*2 should be equal 4",
				AssertionEqual:
					mul: 2, 2
					4
			SkippedCase:
				"Temporary off, failed",
				Case:
					"2*2 should be equal 5",
					AssertionEqual:
						mul: 2, 2
						5
			Suite:
				"sub",
				Case:
					"2+2 should be equal 4",
					AssertionEqual:
						plus: 2, 2
						4
				Case:
					"3+3 should be equal 6",
					AssertionEqual:
						plus: 3, 3
						6
		.run()
```

Suite and Case composition is not strangely. Key moment - Assertion this is a object.
Each test should have only one assertion. We throw out code and describe all tests over Object composition.
This helped to avoid the problem of lost tests. Test invocation is a case itself.

# Dictionary

## Suite

Test set.

## Case

This is a test.
Gets two arguments: description and Assertion.
Class Under Tests should be construct for each tests separately.
In some cases you may want to create helper classes only for testing.
This is the only time when we write something for testing.

## Assertion

Test assertion.
Test framework has a standard set of asserions (Equal, In, Except, etc...)
You can add your own assertions.

# Questions

1. Describe all tests in one place - is bad. But if you describe the tests elsewhere, the problem of lost sets is possible.
1. Test shuffling is hard...
1. Need to thinking about different format of report.
