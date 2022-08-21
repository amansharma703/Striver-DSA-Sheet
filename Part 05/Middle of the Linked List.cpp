// PROBLEM 
// https://leetcode.com/problems/middle-of-the-linked-list/


/*
    Solution 1 : Naive Method
    Time complexity : O(N) + O(N/2) ~ O(N)
    Space Complexity : O(1)
*/


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
    	ListNode* temp = head;
    	while(temp) {
        	n++;
        	temp = temp->next;
    	}
   	 
    	temp = head;
   	 
    	for(int i = 0; i < n / 2; i++) {
        	temp = temp->next;
    	}
   	 
    	return temp;
    }
};




/*
    Solution 2 : 2 Pointer approach ||  Tortoise-Hare-Approach
    Time complexity : O(N) 
    Space Complexity : O(1)
*/


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};