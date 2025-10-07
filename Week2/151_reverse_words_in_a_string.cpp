#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());
        
        int n = s.length();
        int idx = 0;  // Index to place characters in result
        
        // Step 2: Process each word
        for (int start = 0; start < n; start++) {
            // Skip spaces
            if (s[start] != ' ') {
                // Add space before word (except for the first word)
                if (idx != 0) {
                    s[idx++] = ' ';
                }
                
                // Find the end of the current word
                int end = start;
                while (end < n && s[end] != ' ') {
                    s[idx++] = s[end++];
                }
                
                // Step 3: Reverse the current word to get correct order
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                
                // Move start to the end of current word
                start = end;
            }
        }
        
        // Step 4: Resize string to remove trailing characters
        s.resize(idx);
        
        return s;
    }
};

/*
Problem: Reverse Words in a String - LeetCode #151

Description:
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters.
The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.

Algorithm:
I used an in-place two-pointer approach with double reversal:
1. Reverse the entire string
2. Iterate through the string and identify words
3. Reverse each individual word back to correct order
4. Handle extra spaces by compacting the string
5. Resize to remove trailing characters

This approach is more space-efficient than using extra arrays or vectors.

Time Complexity: O(n) where n is the length of the string
- O(n) to reverse entire string
- O(n) to process and reverse individual words
- Overall: O(n)

Space Complexity: O(1) - in-place modification (excluding the input/output)

Example:
Input: s = "the sky is blue"
Output: "blue is sky the"

Input: s = "  hello world  "
Output: "world hello"

Input: s = "a good   example"
Output: "example good a"
*/
