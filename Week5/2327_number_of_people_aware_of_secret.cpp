#include <vector>

class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    // Approach: Dynamic Programming
    // dp[i] = number of people who learn the secret on day i
    // We need to track who can share (past delay) and who forgets (past forget)

    const int MOD = 1e9 + 7;

    // dp[i] represents number of NEW people learning secret on day i
    std::vector<long long> dp(n + 1, 0);
    dp[1] = 1; // One person knows the secret on day 1

    // sharing = running sum of people who can share (learned between delay and
    // forget ago)
    long long sharing = 0;

    for (int i = 2; i <= n; i++) {
      // Add people who can now share (learned on day i - delay)
      if (i - delay >= 1) {
        sharing = (sharing + dp[i - delay]) % MOD;
      }

      // Remove people who forget (learned on day i - forget)
      if (i - forget >= 1) {
        sharing = (sharing - dp[i - forget] % MOD + MOD) % MOD;
      }

      // New people learning today = all people currently sharing
      dp[i] = sharing;
    }

    // Count all people who still remember (learned within last 'forget' days)
    long long result = 0;
    for (int i = n - forget + 1; i <= n; i++) {
      if (i >= 1) {
        result = (result + dp[i]) % MOD;
      }
    }

    return result;
  }
};

// Time Complexity: O(n) - Single pass through days
// Space Complexity: O(n) - DP array of size n
