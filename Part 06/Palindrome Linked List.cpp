// PROBLEM 
// https://leetcode.com/problems/palindrome-linked-list/


/*
    Solution 1 : Naive
    Time complexity : O(N)
    Space Complexity : O(N)

    Take all the node values into a vector and check if the resultant vector is palindrome or not.
*/


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;
        for(ListNode *curr = head; curr!= NULL;curr = curr->next)
            nums.push_back(curr->val);
        int low =0;
        int high = nums.size()-1;
       while(low<high){
           if(nums[low] != nums[high]) return false;
           low++;
           high--;
       }
        return true;
    }
};




/*
    Solution 2 : Optimized 
    Time complexity : O(N)
    Space Complexity : O(1)

    1. Find Middle of the Linked List.
    2. Reverse the latter half of the Linked List.
    3. Compare corresponding nodes in the two halves of the lists.
*/


class Solution {
public:
    // reverse a linked list code
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* n;
        
        while(cur!=NULL){
            
            n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;
            
        }
        
        return prev;
    }
    
    
    bool isPalindrome(ListNode* head) {
        // find middle of the linked list
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        
        // reverse the latter half of the list
        ListNode* revHead = reverseList(slow);
        
        
        // traverse in each half to check is it palindrome or not
        ListNode* firstHalf = head;
        ListNode* secondHalf = revHead;
        
        while(secondHalf != NULL){
            if(firstHalf->val != secondHalf->val){
                return false; // not palindrome;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return true; // palindrome
    }
};