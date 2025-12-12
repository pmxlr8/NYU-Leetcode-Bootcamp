#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
    // Approach: Dynamic Programming
    // dp[i] = true if s[0..i-1] can be segmented into dictionary words

    // Create a hash set for O(1) word lookup
    std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

    int n = s.length();

    // dp[i] represents whether s[0..i-1] can be broken into words
    std::vector<bool> dp(n + 1, false);
    dp[0] = true; // Empty string can be segmented

    for (int i = 1; i <= n; i++) {
      // Try all possible last words ending at position i
      for (int j = 0; j < i; j++) {
        // If s[0..j-1] can be segmented AND s[j..i-1] is a valid word
        if (dp[j] && wordSet.count(s.substr(j, i - j))) {
          dp[i] = true;
          break; // No need to check further
        }
      }
    }

    return dp[n];
  }
};

// Time Complexity: O(n^3) - Two nested loops O(n^2) and substr takes O(n)
//                  Can be optimized with Trie to O(n^2)
// Space Complexity: O(n + m) - DP array O(n) + word set O(m *
// average_word_length)
