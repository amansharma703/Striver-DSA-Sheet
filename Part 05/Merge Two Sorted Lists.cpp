// PROBLEM 
// https://leetcode.com/problems/merge-two-sorted-lists/


/*
    Solution 1 : Recursive
    Time complexity : O(N) 
    Space Complexity : O(1)
*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL)  return l1;
        
        ListNode *res;
        
        if(l1->val >= l2->val){
            res = l2;
            res->next = mergeTwoLists(l1, l2->next);
        }
        else{
            res = l1;
            res->next = mergeTwoLists(l1->next, l2);
        }
        return res;
    }
};




/*
    Solution 2 : Iterative
    Time complexity : O(N) 
    Space Complexity : O(1)
*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)
            return l2;
        
        if(l2 == NULL)
            return l1;
        
        if(l1->val > l2->val){
            swap(l1, l2);
        }
        
        ListNode* startNode = l1;
        
        while(l1 != NULL && l2 != NULL){
            
            ListNode *temp = l1;
            
            while(l1 != NULL && l1->val <= l2 -> val){
                temp = l1;
                l1 = l1->next;
            }
            
            temp->next = l2;
            
            swap(l1, l2);
            
        }
        
        return startNode;
        
    }
};