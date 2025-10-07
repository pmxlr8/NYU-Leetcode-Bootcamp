#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        
        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Step 2: Check for sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        // Step 3: Convert digits to integer
        long result = 0;  // Use long to detect overflow
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            
            // Step 4: Check for overflow/underflow
            // Check before applying sign to avoid overflow in the multiplication
            if (result * sign > INT_MAX) {
                return INT_MAX;
            }
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            
            i++;
        }
        
        // Apply sign and return
        return (int)(result * sign);
    }
};

/*
Problem: String to Integer (atoi) - LeetCode #8

Description:
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

Algorithm:
1. Skip leading whitespaces
2. Determine the sign (+ or -)
3. Read digits and convert to integer
4. Handle overflow/underflow by clamping to [INT_MIN, INT_MAX]

Time Complexity: O(n) where n is the length of the string
Space Complexity: O(1) - only using constant extra space

Example:
Input: s = "42"
Output: 42

Input: s = "   -42"
Output: -42

Input: s = "4193 with words"
Output: 4193
*/
