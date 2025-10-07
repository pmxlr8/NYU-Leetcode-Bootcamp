#include <vector>
#include <utility> // For std::swap

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        // Process the array until the mid pointer crosses the high pointer.
        while (mid <= high) {
            switch (nums[mid]) {
                case 0:
                    // If the element is 0, swap it with the element at the low pointer.
                    std::swap(nums[low], nums[mid]);
                    low++;
                    mid++;
                    break;
                case 1:
                    // If the element is 1, it's in the right place. Move to the next element.
                    mid++;
                    break;
                case 2:
                    // If the element is 2, swap it with the element at the high pointer.
                    std::swap(nums[mid], nums[high]);
                    // Don't increment mid because the swapped element at mid needs to be checked.
                    high--;
                    break;
            }
        }
    }
};
