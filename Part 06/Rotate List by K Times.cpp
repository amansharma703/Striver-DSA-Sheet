// PROBLEM 
// https://leetcode.com/problems/rotate-list/


/*
    Solution 1 : HashMap
    Time complexity : O(N)
    Space Complexity : O(N)

    First count the len of nodes.
    Now we know every len times, the list retains to the initial position. So K = K % len.
    If K = 0, awesome, no rotation, return head as it is.

    Now lets suppose K = 2 in the list 1->2->3->4->5->NULL.
    Last 2 nodes comes in front of list.
    So device a strategy to split the list at K nodes from back (1->2->3->NULL and 4->5->NULL)
    Now attach 5 (last node) next to 1 (initial head).
    And return 4 (new head).
    Where to split ? After len - K - 1 iterations from start HEAD.
*/




class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // edge cases 
        if (!head || !head->next || k == 0) return head;
        
        ListNode *cur = head;
        ListNode* lastNode = head;
        
        // compute the length
        int len = 0;
        while (cur != NULL) {
            ++len;
            lastNode = cur;
            cur = cur->next;
        }
         
        k = k % len; 
        if(k == 0){
            return head;
        }
        int skip = len - k - 1;
        cur = head;    
        
        while(skip--){
            cur = cur->next;
        }
        
        ListNode* newHead = cur->next;
        cur->next  = NULL;
        lastNode-> next = head;
        
        return newHead; 

    }
};