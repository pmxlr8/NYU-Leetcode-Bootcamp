#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
    // Approach: Use a monotonic decreasing stack
    // Stack stores indices of temperatures we haven't found a warmer day for

    int n = temperatures.size();
    std::vector<int> result(n, 0); // Initialize with 0 (default: no warmer day)
    std::stack<int> stack;         // Stack of indices

    for (int i = 0; i < n; i++) {
      // While current temperature is warmer than temperature at stack top
      while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
        int prevIndex = stack.top();
        stack.pop();
        result[prevIndex] = i - prevIndex; // Days until warmer temperature
      }

      // Push current index onto stack
      stack.push(i);
    }

    // Remaining indices in stack have no warmer day (already 0 in result)
    return result;
  }
};

// Time Complexity: O(n) - Each element is pushed and popped at most once
// Space Complexity: O(n) - Stack can contain at most n elements
