#ifndef MYSTACK_H
#define MYSTACK_H

#include "Stack.h"

struct Node {
  double data;
  Node *next;
};

struct LinkedList {
  Node *head;
  Node *tail;
};
class MyStack: public Stack {
  Node *head;

public:
  MyStack();
  // See Stack.h for descriptions.
  void   clear();
  bool   is_empty() const;
  void   push(double item);
  double pop();
  double top() const;
  void print() const;
  ~MyStack();
};

#endif
