#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
    // Approach: Use HashMap to count frequencies, then bucket sort
    // Bucket sort gives O(n) time complexity

    // Step 1: Count frequencies using a hash map
    std::unordered_map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
    }

    // Step 2: Create buckets where index = frequency
    // Maximum frequency possible is n (all elements same)
    int n = nums.size();
    std::vector<std::vector<int>> buckets(n + 1);

    for (auto &[num, count] : freq) {
      buckets[count].push_back(num);
    }

    // Step 3: Collect k most frequent elements from buckets (high to low
    // frequency)
    std::vector<int> result;
    for (int i = n; i >= 0 && result.size() < k; i--) {
      for (int num : buckets[i]) {
        result.push_back(num);
        if (result.size() == k)
          break;
      }
    }

    return result;
  }
};

// Time Complexity: O(n) - Count frequencies O(n), bucket sort O(n), collect
// results O(k) Space Complexity: O(n) - Hash map and buckets both use O(n)
// space
