#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        // Initialize two pointers, one at the start and one at the end.
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int currentSum = numbers[left] + numbers[right];

            if (currentSum == target) {
                // Found the pair. Return their 1-based indices.
                return {left + 1, right + 1};
            } else if (currentSum < target) {
                // The sum is too small, so we need a larger number.
                // Move the left pointer to the right.
                left++;
            } else {
                // The sum is too large, so we need a smaller number.
                // Move the right pointer to the left.
                right--;
            }
        }
        
        // Per the problem description, a solution always exists,
        // so this part of the code should not be reached.
        return {};
    }
};
