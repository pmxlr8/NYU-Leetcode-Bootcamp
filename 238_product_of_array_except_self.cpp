#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n);

        // First pass: Calculate prefix products
        // answer[i] will contain the product of all elements to the left of i.
        answer[0] = 1;
        for (int i = 1; i < n; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }

        // Second pass: Calculate suffix products and combine with prefix products
        // R will hold the product of all elements to the right of i.
        int R = 1;
        for (int i = n - 1; i >= 0; i--) {
            // answer[i] already has the prefix product. Multiply it by the suffix product.
            answer[i] = answer[i] * R;
            // Update R for the next iteration.
            R *= nums[i];
        }

        return answer;
    }
};
