#include <stack>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Approach: Use slow/fast pointers to find middle,
        // reverse the second half, then compare both halves.
        
        if (!head || !head->next) return true;
        
        // Step 1: Find the middle using slow/fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half starting from slow->next
        ListNode* secondHalf = reverseList(slow->next);
        
        // Step 3: Compare the first half with the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalfCopy = secondHalf; // Keep reference to restore later
        
        bool isPalin = true;
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        // Step 4: Restore the list (optional but good practice)
        slow->next = reverseList(secondHalfCopy);
        
        return isPalin;
    }
    
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};

// Time Complexity: O(n) - We traverse the list a constant number of times
// Space Complexity: O(1) - We only use a few pointers, no extra space proportional to input
