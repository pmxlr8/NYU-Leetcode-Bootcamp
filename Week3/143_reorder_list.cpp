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
  void reorderList(ListNode *head) {
    // Approach:
    // 1. Find the middle of the list
    // 2. Reverse the second half
    // 3. Merge the two halves alternately

    if (!head || !head->next)
      return;

    // Step 1: Find the middle using slow/fast pointers
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Step 2: Reverse the second half starting from slow->next
    ListNode *secondHalf = slow->next;
    slow->next = nullptr; // Split the list
    secondHalf = reverseList(secondHalf);

    // Step 3: Merge the two halves alternately
    ListNode *firstHalf = head;

    while (secondHalf) {
      ListNode *temp1 = firstHalf->next;
      ListNode *temp2 = secondHalf->next;

      firstHalf->next = secondHalf;
      secondHalf->next = temp1;

      firstHalf = temp1;
      secondHalf = temp2;
    }
  }

private:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    return prev;
  }
};

// Time Complexity: O(n) - Each step traverses the list once
// Space Complexity: O(1) - Only using pointers, no extra data structures
