// PROBLEM 
// https://leetcode.com/problems/powx-n/


/*
    Solution 1 : 
    Time complexity : O(1) 
    Space Complexity : O(1)

    We want to delete C and we have access to C only. Not HEAD (A).

    Solution :- Copy Value of D in C. And point C->E (C->next = C->next->next).

    Edge Case :- This solution won't work if it is the tail node to be asked for deletion. And the question also specefies that the tail node won't be asked to delete.
*/



class Solution {
public:
    // 4->5->1->9    n=5
    void deleteNode(ListNode* node) {
        // 4->1->1->9 
        node->val = node-> next-> val;
        // 4->1->9
        node->next = node->next->next;
    }
};