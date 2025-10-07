# Week 2: Strings and HashMap

This week, I focused on string manipulation problems and hash map techniques. These problems helped me strengthen my understanding of efficient string processing and the power of hash maps for tracking character frequencies.

## Problems Solved

### 1. String to Integer (atoi) - LeetCode #8
**File:** `8_string_to_integer_atoi.cpp`

For this problem, I implemented a step-by-step state machine approach to convert a string to an integer. The key challenges were:
- Handling leading whitespaces
- Detecting and applying the correct sign
- Converting digit characters to their integer values
- Preventing integer overflow/underflow

I used a `long` variable to detect overflow before it happens, then clamped the result to `INT_MIN` and `INT_MAX` boundaries. This ensures the function behaves correctly for edge cases like `"2147483648"` (which exceeds INT_MAX).

**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

### 2. Find All Anagrams in a String - LeetCode #438
**File:** `438_find_all_anagrams_in_a_string.cpp`

For the anagrams problem, I used a **sliding window approach with frequency maps**. The strategy was:
1. Build a frequency map for the pattern string `p`
2. Maintain a sliding window of size `p.length()` over string `s`
3. Track character frequencies in the current window using another hash map
4. Compare the window's frequency map with the pattern's frequency map
5. When they match, record the starting index

The sliding window technique makes this efficient because I only need to update two characters (add one, remove one) at each step instead of recalculating the entire window. Using hash maps for frequency comparison made it easy to check if two substrings are anagrams.

**Time Complexity:** O(n) where n is the length of string `s`  
**Space Complexity:** O(1) - the maps store at most 26 characters

---

### 3. Reverse Words in a String - LeetCode #151
**File:** `151_reverse_words_in_a_string.cpp`

I solved this problem using a **double reversal technique** that works in-place:
1. Reverse the entire string
2. Iterate through and identify individual words
3. Reverse each word back to its correct order
4. Handle multiple spaces by compacting them to single spaces

This approach was particularly interesting because it avoids using extra space for splitting the string into an array of words. The double reversal is a clever trick: reversing the whole string puts words in the right order but backwards, then reversing each word individually fixes their internal character order.

**Time Complexity:** O(n)  
**Space Complexity:** O(1) - in-place modification

---

## Key Takeaways

This week taught me:
- **Hash Maps** are incredibly powerful for frequency counting and pattern matching
- **Sliding window** technique can dramatically improve efficiency for substring problems
- **In-place algorithms** can save space but require careful index management
- String problems often have edge cases around whitespace and boundaries that need careful handling

I'm getting more comfortable with these common patterns and can see how they apply to many different problem types!
