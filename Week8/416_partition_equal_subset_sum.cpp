#include <numeric>
#include <vector>

class Solution {
public:
  bool canPartition(std::vector<int> &nums) {
    // Approach: 0/1 Knapsack variant using Dynamic Programming
    // We need to find a subset that sums to totalSum / 2

    int totalSum = std::accumulate(nums.begin(), nums.end(), 0);

    // If total sum is odd, we cannot partition into two equal subsets
    if (totalSum % 2 != 0)
      return false;

    int target = totalSum / 2;
    int n = nums.size();

    // dp[i] = true if we can achieve sum i using some subset of nums
    std::vector<bool> dp(target + 1, false);
    dp[0] = true; // We can always achieve sum 0 (empty subset)

    for (int num : nums) {
      // Traverse backwards to avoid using the same number twice
      for (int j = target; j >= num; j--) {
        // dp[j] is true if:
        // 1. It was already true (we don't use current num), OR
        // 2. dp[j - num] was true (we use current num)
        dp[j] = dp[j] || dp[j - num];
      }
    }

    return dp[target];
  }
};

// Time Complexity: O(n * sum) - Where n is array length and sum is total sum /
// 2 Space Complexity: O(sum) - 1D DP array
