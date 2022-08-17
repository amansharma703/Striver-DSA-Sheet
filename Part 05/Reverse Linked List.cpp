// PROBLEM 
// https://leetcode.com/problems/reverse-linked-list/


/*
    Solution 1 : Bruteforce - Using Vector
    Time complexity : O(N) 
    Space Complexity : O(N)
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> nums;
        for(ListNode *curr = head; curr!= NULL;curr = curr->next)
            nums.push_back(curr->val);
        
        for(ListNode *curr = head; curr!= NULL;curr = curr->next){
            curr->val = nums.back();
            nums.pop_back();
        }
        return head;
    }
};




/*
    Solution 2 : Recursive
    Time complexity : O(N) 
    Space Complexity : O(1) but take recursion stack space
*/


class Solution {
public:
    ListNode* reverseList(ListNode* &head) {

        if (head == NULL||head->next==NULL)
            return head;

        ListNode* nnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nnode;
    }
};



/*
    Solution 3 : Iterative
    Time complexity : O(N) 
    Space Complexity : O(1) 
*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode *curr = head, *prev = NULL;
        while(curr!= NULL){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
