# Postfix Calculator
by: Alvin Tu

## Overview

In this project I implemented a simple calculator that understands Reverse
Polish Notation (postfix notation). This is an alternative way to
write mathematical expressions.  Each operator is written _after_  its operands.
For example, the standard (infix) expression...

```
5 - 4
```
becomes:

```
5 4 -
```

And the more complicated equation...

```
((3 + 12) * (5 - 2)) ^ 3
```

...would become:

```
3 12 + 5 2 - * 3 ^
```

Reverse Polish Notation is much easier for computers to work with (no
parentheses are required).  In fact, Reverse Polish Notation can be thought of
as a stream of instructions for a very simple type of computer: a **stack machine**.


## Stack Machines

A stack machine is a  computer that stores its data on a stack. To evaluate an
RPN expression, a stack machine starts with an empty stack.  It then reads input
as a sequence of **tokens**, from left to right:

- If the token is a number, the stack machine pushes it onto the stack.
- If the token is an operator,  the stack machine pops numbers off of the stack,
  performs the operation on those numbers, and pushes the result onto the stack.

If everything goes well,  there will be one number on the stack after all tokens
have been processed.  This is the final value of the input expression.

## The Stack

The  `Stack.h`  file describes an  abstract  Stack  data structure.  I implemented a
concrete Stack (instead of using one from the C++ standard library) in `MyStack.h` and `MyStack.cpp` that 
shares all of the functions that the standard stack does: clear the stack, check if the stack is empty, 
push items onto the stack, pop the first item on the stack, get the top item, and print what's on the stack. 

## The Calculator

This calculator uses my stack implementation to take in inputs in postfix notation and outputs the correct calculation. To do this, 
I first parse in the items that were inputted. Then, the calculator will push all of them onto the stack, and pop one by one until an operand
is popped. When that happens, the operation is performed and the calculated value is pushed back onto the stack. This repeats until there is
only one number left. 

There are  a few things that could go wrong.  If you hit these cases,  print the
correct error message and move on to the next line of input.  If multiple errors
apply, print whichever comes first in this list:

- Print `Unknown token.` if you encounter a token that's not a number or one of
  the operators described above.
- Print `Not enough operands.` if there aren't enough numbers on the stack for
  the current operator.
- Print `Division by zero.` if you ever attempt to divide (or take a remainder
  after division) by zero.
- Print `Too many operands.` if there's more than one number on the stack after
  evaluating the entire expression.
- Print `No expression.` if the stack is empty after evaluating the entire
  expression (this can only happen if there are no tokens at all).

When you reach  the end of the input stream,  the program should exit.  You can
simulate this by sending an end-of-file (EOF) signal to your program. Do this by
pressing  `Ctrl` + `D` on Linux and Mac,  or by pressing  `Ctrl` + `Z`  and then
`Enter` on Windows.

This is how it should look like: 

```
[alvintu@Alvins-Laptop]$ ./calc
hello
Unknown token.
5 4 -
= 1
1 2 + 7 3 - * 2 ^
= 144
```

## Download
1. Click the green "Code" button
2. Click download zip or open your Terminal and paste `git clone git@github.com:alvin-tu/Postfix-Calculator.git`
3. Extract the files

