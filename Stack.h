#ifndef STACK_H
#define STACK_H


class Stack {
public:
  // Create and return a new stack.
  static Stack* create();

public:

  // Remove everything from the stack.
  virtual void clear() = 0;

  // Is this stack empty?
  virtual bool is_empty() const = 0;

  // Push an item onto the top of the stack.
  virtual void push(double item) = 0;

  // Pop an item off the top of the stack and return it.
  // If the stack is empty, throw std::underflow_error.
  virtual double pop() = 0;

  // Return the item currently on top of the stack.
  // If the stack is empty, throw std::underflow_error.
  virtual double top() const = 0;

  virtual ~Stack() {}
};

#endif
