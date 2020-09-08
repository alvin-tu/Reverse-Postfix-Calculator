CXXFLAGS = -g -std=c++17 -Wall -Wextra -Werror
CXX      = g++

# These targets don't create any files:
.PHONY: all clean

# Magic Variables!
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
#  $@ is the name of the target
#  $+ is a list of all the dependencies
#  $< is the first dependency

all: calc test

calc: calc.o MyStack.o Stack.o
	${CXX} $(CXXFLAGS) -o $@ $+

test: test.o MyStack.o Stack.o
	${CXX} $(CXXFLAGS) -o $@ $+


calc.o: calc.cpp MyStack.h Stack.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

test.o: test.cpp MyStack.h Stack.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

MyStack.o: MyStack.cpp MyStack.h Stack.h
	${CXX} $(CXXFLAGS) -c -o $@ $<

Stack.o: Stack.cpp Stack.h
	${CXX} $(CXXFLAGS) -c -o $@ $<


clean:
	rm -f calc test calc.o test.o MyStack.o Stack.o
