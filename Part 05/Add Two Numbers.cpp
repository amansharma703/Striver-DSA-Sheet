// PROBLEM 
// https://leetcode.com/problems/add-two-numbers/


/*
    Solution 1 : Bruteforce - Using Vector
    Time complexity : O(max(M, N)) -> where M and N are length of both lists respectively. 
    Space Complexity : O(max(M, N)) -> where M and N are length of both lists respectively.


    Elementary addition technique simulated through a linked list traversals. 
    Fetch corresponding position, get the value, add it, add carry if available, 
    and then set the value to the respective position in the list. 
*/



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        int carry = 0;
        
        while(l1 != NULL || l2 != NULL || carry == 1){
            int sum = 0;
            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode *node = new ListNode(sum % 10);
            curr->next = node;
            curr = curr->next;
        }
        return dummy->next;
    }
};