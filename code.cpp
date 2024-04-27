#include <iostream>
#include <vector>

// TRYING TO DO THIS LIKE OPTION 1 IMPLEMENTING MY OWN STACK CLASS WITH A
// VECTOR.

// create a stack class
class Stack {
 private:
  std::vector<char> data;

 public:
  // push function to add char to the stack
  void push(char c) { data.push_back(c); }

  // removes top element from stack and returns it unless stack is empty
  char pop() {
    if (data.empty()) {
      std::cerr << "Error: Stack is empty." << std::endl;
      exit(EXIT_FAILURE);
    }
    char top = data.back();
    data.pop_back();
    return top;
  }

  // check if empty
  bool isEmpty() { return data.empty(); }
};
// check if the chars are balanced out
bool isBalanced(const std::string& expression) {
  Stack stack;
  for (char c : expression) {
    if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      if (stack.isEmpty()) {
        return false;  // More closing than opening parentheses
      }
      stack.pop();
    }
  }
  return stack.isEmpty();  // Check if any opening parentheses left unmatched
}

int main() {
  std::string expression;
  std::cout << "Enter an expression: ";
  std::cin >> expression;

  if (isBalanced(expression)) {
    std::cout << "Balanced" << std::endl;
  } else {
    std::cout << "Not Balanced" << std::endl;
  }

  return 0;
}
