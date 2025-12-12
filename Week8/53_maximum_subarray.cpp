#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    // Approach: Kadane's Algorithm
    // Track current subarray sum and maximum sum seen so far

    int maxSum = nums[0];     // Maximum subarray sum found
    int currentSum = nums[0]; // Current subarray sum ending at current position

    for (int i = 1; i < nums.size(); i++) {
      // Either extend the previous subarray or start a new one from current
      // element
      currentSum = std::max(nums[i], currentSum + nums[i]);

      // Update maximum if current sum is larger
      maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
  }
};

// Time Complexity: O(n) - Single pass through the array
// Space Complexity: O(1) - Only using two variables
