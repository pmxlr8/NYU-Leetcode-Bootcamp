#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int coinChange(std::vector<int> &coins, int amount) {
    // Approach: Bottom-up Dynamic Programming
    // dp[i] = minimum number of coins needed to make amount i

    // Initialize with amount + 1 (impossible value, acts as infinity)
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0; // 0 coins needed for amount 0

    // For each amount from 1 to target
    for (int i = 1; i <= amount; i++) {
      // Try each coin
      for (int coin : coins) {
        if (coin <= i) {
          // dp[i] = min of current value or (1 + dp[i - coin])
          dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
      }
    }

    // If dp[amount] is still the impossible value, return -1
    return dp[amount] > amount ? -1 : dp[amount];
  }
};

// Time Complexity: O(amount * n) - Where n is the number of coin denominations
// Space Complexity: O(amount) - 1D DP array
