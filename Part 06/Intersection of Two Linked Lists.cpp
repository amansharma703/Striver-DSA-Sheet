// PROBLEM 
// https://leetcode.com/problems/rotate-list/



/*
    Solution 1 : 2 pointer
    Time complexity : O(N + M)
    Space Complexity : O(1)

    Take two pointers a and b initially at head of ListA and ListB respectively.
    Start traversing in both linked list. Increement both pointers by 1 step at each step.
    Whenever a reaches end of ListA, make it point to ListB head.
    Similarly when b reaches at the end of ListB, make it point to ListA head.

    After at max 2 times whole traversal of both lists, both pointers will reach at an common intersection point. Or they simultaneously will reach at NULL, referring no intersection.
*/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
    
        ListNode *a = headA;
        ListNode *b = headB;

        //if a & b have different len, then we will stop the loop after second iteration
        while( a != b){
            //for the end of first iteration, we just reset the pointer to the head of another linkedlist
            a = a == NULL? headB : a->next;
            b = b == NULL? headA : b->next;    
        }

        return a;

    }
};