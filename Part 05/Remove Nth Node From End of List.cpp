// PROBLEM 
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/


/*
    Solution 1 : Naive
    Time complexity : O(N) - 2 pass
    Space Complexity : O(1)

    Count total number (TOT) of nodes, and delete while traversal on the next turn from (TOT - n) position
*/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        //pass1
        for(ListNode *curr = head; curr != NULL; curr = curr->next)
            len++;
        ListNode *curr = head;
        //pass2
        for(int i=1; i<len-n;i++){
            curr = curr->next;
        }
        ListNode *temp;
        if(head->next == NULL){    //handle corner case
            delete(head);
            return NULL;
        }
        if(n==len){                // corner case 2
            temp = head;
            head = head->next;
            delete(temp);
            return head;    
        }
        temp = curr->next;
        curr->next = curr->next->next;
        delete(temp);
        return head;
    }
};




/*
    Solution 2 : 2 Pointer Approach
    Time complexity : O(N) - 1 pass
    Space Complexity : O(1)

    Mantain 2 pointers, SLOW and FAST. 
    Make FAST pointer initially move n position.
    Then SLOW and FAST pointers go hand in hand, until FAST pointer meets the last position.
    Then delete the asserted node by making SLOW point to its next of next location.

    Edge case :- What if n == length of the list? Here we need to remove the first element of the list. 
    Take care of it separately.
*/



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* fast = head;
        ListNode* slow = head;
        
        while(n--){
            fast = fast->next;
        }
        
        if(fast == NULL){ // edge case
            return slow->next;
        }
        
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        
        return head;
    }
};