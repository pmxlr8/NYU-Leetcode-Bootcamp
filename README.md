# NYU Tandon LeetCode Bootcamp - Fall 2025

This repository contains my solutions to the weekly homework problems for the NYU Tandon LeetCode Bootcamp.

---

## Week 1: Lists, Arrays, and Sorting

This week focused on fundamental array manipulation techniques like the two-pointer method, prefix/suffix products, and in-place sorting.

### 1. Two Sum II - Input Array Is Sorted

* **LeetCode Link:** [167. Two Sum II - Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
* **Solution File:** `167_two_sum_II.cpp`
* **Approach:** Used the **Two Pointers** technique. With a sorted array, a `left` pointer at the start and a `right` pointer at the end can efficiently find the target sum by moving inward. This gives an $O(n)$ time and $O(1)$ space solution.

### 2. Product of Array Except Self

* **LeetCode Link:** [238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)
* **Solution File:** `238_product_of_array_except_self.cpp`
* **Approach:** To avoid using division, I used a two-pass approach. The first pass calculates the product of all elements to the left of each index (prefix products). The second pass calculates the suffix products and multiplies them with the stored prefix products to get the final result in $O(n)$ time and $O(1)$ extra space.

### 3. Sort Colors

* **LeetCode Link:** [75. Sort Colors](https://leetcode.com/problems/sort-colors/)
* **Solution File:** `75_sort_colors.cpp`
* **Approach:** Implemented the **Dutch National Flag algorithm** for a single-pass, in-place sort. Three pointers (`low`, `mid`, `high`) are used to partition the array into sections of `0`s, `1`s, and `2`s, achieving an $O(n)$ time and $O(1)$ space solution.

---

## Week 2: Strings and HashMap

*(Solutions coming soon...)*
