// PROBLEM 
// https://leetcode.com/problems/reverse-nodes-in-k-group/


/*
    Solution 1 : 
    Time complexity : O(N)
    Space Complexity : O(1)
*/


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head, *prev = NULL, *next= NULL;
        // corner case for checking k not beyond of remaining list
        for(int i=0; curr && i<k-1; i++){
                curr = curr-> next;
            }
        if(!curr) return head;
        
        // normal reversal to k node
        curr=head;
        int count = 0;
        while(curr!= NULL && count<k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(next!= NULL){
            head->next  = reverseKGroup(next,k);
        } 
        return prev;
    }
};