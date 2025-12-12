#include <stack>

class MyQueue {
private:
  std::stack<int> inputStack;  // Stack for push operations
  std::stack<int> outputStack; // Stack for pop/peek operations

  // Transfer elements from inputStack to outputStack when outputStack is empty
  void transferIfNeeded() {
    if (outputStack.empty()) {
      while (!inputStack.empty()) {
        outputStack.push(inputStack.top());
        inputStack.pop();
      }
    }
  }

public:
  MyQueue() {
    // Constructor - stacks are initialized empty by default
  }

  void push(int x) {
    // Always push to the input stack
    inputStack.push(x);
  }

  int pop() {
    // Transfer elements if needed, then pop from output stack
    transferIfNeeded();
    int front = outputStack.top();
    outputStack.pop();
    return front;
  }

  int peek() {
    // Transfer elements if needed, then peek from output stack
    transferIfNeeded();
    return outputStack.top();
  }

  bool empty() {
    // Queue is empty only if both stacks are empty
    return inputStack.empty() && outputStack.empty();
  }
};

// Time Complexity:
//   - push: O(1)
//   - pop: Amortized O(1) - Each element is moved at most once from input to
//   output
//   - peek: Amortized O(1)
//   - empty: O(1)
// Space Complexity: O(n) - We store all elements across two stacks
