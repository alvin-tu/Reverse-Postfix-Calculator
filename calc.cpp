#include "Stack.h"
#include "MyStack.h"
#include <cmath>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

// function to check if I have an operator in input
bool isOperator(const std::string& input) {
	if (input == "+" || input == "-" || input == "*" || input == "/" 
  || input == "^" || input == "%" || input == "~") {
		return true;
	}
	else {
		return false;
	}
}

int main() {
  MyStack* stack = new MyStack();
  std::string line;

  // read in inputs
  while(std::getline(std::cin, line)) {
    std::stringstream ss;
    ss << line;

    // initialize a bunch of counting variables
		std::string tmp;
    double found;
    int numCount = 0;
    int testCount = 0;
    int minCount = 0;
    int plusCount = 0;
    int dotCount = 0;
    int totalCount = 0;
    int opTotalCount = 0;
    bool noExpression = true;
    bool zero = false;
    bool unknown = false;
    bool punct = false; 
    int l = line.length();

    while(ss >> tmp) {
      // test if input is a double with trailing char 
      for (int j = 0; j < l; j++) {
        if(isalpha(line[j])) {
          std::cerr << "Unknown token." << std::endl;
          unknown = true;
          break;
        } 
      }
      if (unknown) {
        stack->clear();
        break;
      }

      // test for punctuation
      int n = tmp.length();
      for(int i = 0; i < n; i ++) {
        if(tmp[i] == '-' && minCount == 0 && testCount == 0 && plusCount != 1) {
          minCount += 1;
        } else if(tmp[i] == '+' && plusCount == 0 && testCount == 0 && minCount != 1){
          plusCount += 1;
        } else if (tmp[i] == '.' && dotCount == 0) {
          dotCount += 1;
        } else if(isdigit(tmp[i])) {
          testCount += 1;
        } else if(tmp[i] == '-' && (minCount == 1 || plusCount == 1)) {
          std::cerr << "Unknown token." << std::endl;
          punct = true;
          break;
        } else if(tmp[i] == '+' && (plusCount == 1 || minCount == 1)) {
          std::cerr << "Unknown token." << std::endl;
          punct = true;
          break;         
        } else if(tmp[i] == '.' && dotCount == 1) {
          std::cerr << "Unknown token." << std::endl;
          punct = true;
          break;     
        } else if(ispunct(tmp[i]) && (tmp[i] != '.' || tmp[i] != '-' || tmp[i] != '+') && !isOperator(tmp)) {
          std::cerr << "Unknown token." << std::endl;
          punct = true;
          break;  
        } 
      } 
      plusCount = 0;   
      minCount = 0;
      dotCount = 0;
      testCount = 0;

      if(punct) {
        stack->clear();
        break;
      }

      if(isOperator(tmp)) { 
        noExpression = false;
        if(isOperator(tmp) && tmp != "~") {
          opTotalCount += 1;
        }
        if(opTotalCount >= totalCount) {
          std::cerr << "Not enough operands." << std::endl;
          stack->clear();
          break;
        }

        // negate does not change numCount
        if(!stack->is_empty()) {
          if(tmp == "~") {
            stack->push(-1 * stack->pop());
            continue;
          } 
        }

        // check the operation and pop out of stack
        if(!stack->is_empty() && numCount >= 2) {
          double right = stack->pop();
          double left = stack->pop();

          numCount -= 2;

          if(tmp == "+") {
           stack->push(left + right);
           numCount += 1;
          }
          else if(tmp == "-") {
            stack->push(left - right);
            numCount += 1;
          }
          else if(tmp == "*") {
            stack->push(left * right);
            numCount += 1;
          }
          else if(tmp == "/") {
            if(right == 0) {
              zero = true;
              stack->clear();
              std::cerr << "Division by zero." << std::endl;  // error if dividing by 0
              break;
            } else {
              stack->push(left / right);
              numCount += 1;
            }
          } 
          else if(tmp == "^") {
            stack->push(pow(left, right));
            numCount += 1;
          }
          else if (tmp == "%") {
            if(right == 0) {
              zero = true;
              stack->clear();
              std::cerr << "Division by zero." << std::endl;  // error if dividing by 0
              break;
            } else {           
              stack->push(fmod(left, right));
              numCount += 1;
            }
          }
        } 
      }
  
      // extract doubles from string inputs
      if (std::stringstream(tmp) >> found) {
        stack->push(found);
        tmp = "";
        numCount += 1;
        totalCount += 1;
        noExpression = false;
      }

    }

    // check errors and continue if there has been one
    if(zero) {
      continue;
    }
    if(punct) {
      continue;
    }
    if(unknown) {
      continue;
    }
    if(noExpression) {
      std::cerr << "No expression." << std::endl;
      continue;
    }
    if(stack->is_empty()) {
      continue;
    }
    double result = 0;
    if(!stack->is_empty()){ 
      result = stack->pop();
    }
    if (!stack->is_empty()) {
      stack->clear();
      std::cerr << "Too many operands." << std::endl;
      continue;
    }
    std::cout << "= " << result << std::endl;
    
    stack->clear();
  }
  
  delete stack;
  return 0;
}
