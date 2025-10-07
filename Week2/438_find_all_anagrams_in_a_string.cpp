#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int sLen = s.length();
        int pLen = p.length();
        
        // Edge case: if p is longer than s, no anagrams possible
        if (pLen > sLen) {
            return result;
        }
        
        // Create frequency maps for pattern p and current window
        unordered_map<char, int> pFreq, windowFreq;
        
        // Build frequency map for pattern p
        for (char c : p) {
            pFreq[c]++;
        }
        
        // Initialize the first window
        for (int i = 0; i < pLen; i++) {
            windowFreq[s[i]]++;
        }
        
        // Check if first window is an anagram
        if (windowFreq == pFreq) {
            result.push_back(0);
        }
        
        // Slide the window across string s
        for (int i = pLen; i < sLen; i++) {
            // Add new character to the window
            windowFreq[s[i]]++;
            
            // Remove the leftmost character from the window
            char leftChar = s[i - pLen];
            windowFreq[leftChar]--;
            
            // If frequency becomes 0, remove from map to match comparison
            if (windowFreq[leftChar] == 0) {
                windowFreq.erase(leftChar);
            }
            
            // Check if current window is an anagram
            if (windowFreq == pFreq) {
                result.push_back(i - pLen + 1);
            }
        }
        
        return result;
    }
};

/*
Problem: Find All Anagrams in a String - LeetCode #438

Description:
Given two strings s and p, return an array of all the start indices of p's anagrams in s.

Algorithm:
I used a sliding window approach with frequency maps (HashMaps):
1. Create a frequency map for the pattern string p
2. Use a sliding window of size p.length() on string s
3. Maintain a frequency map for the current window
4. Slide the window: add new character, remove old character
5. Compare window frequency with pattern frequency
6. If they match, we found an anagram - record the starting index

Time Complexity: O(n) where n is the length of string s
- We traverse s once with the sliding window
- HashMap comparisons are O(1) amortized for constant alphabet size

Space Complexity: O(1) - HashMaps store at most 26 characters (lowercase English letters)

Example:
Input: s = "cbaebabacd", p = "abc"
Output: [0, 6]
Explanation:
- The substring starting at index 0 is "cba", which is an anagram of "abc"
- The substring starting at index 6 is "bac", which is an anagram of "abc"
*/
