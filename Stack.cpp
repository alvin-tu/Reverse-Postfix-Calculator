#include "Stack.h"
#include "MyStack.h"

Stack* Stack::create() {
  return new MyStack();
}
