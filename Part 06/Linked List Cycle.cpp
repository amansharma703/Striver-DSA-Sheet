// PROBLEM 
// https://leetcode.com/problems/linked-list-cycle/


/*
    Solution 1 : HashMap
    Time complexity : O(N)
    Space Complexity : O(N)

    Use a map to store the NODES, and insert the nodes while traversing the list. 
    If there is a cycle, you will find some node X already in the list previously. This node X is the Cyclic Intersection node. 
    Return TRUE if you detect a cycle. Else if you reach the end of list, return FALSE.
*/


class Solution {
public:
    bool hasCycle(ListNode *head) {
    if(head==NULL)
        return false;
    unordered_map<ListNode*,int> map;
    while(head!=NULL){
        if(map.count(head)>0)
            return true;
        else
            map[head]=1;
        head=head->next;
    }
    return false;
    }
};




/*
    Solution 2 : 2 Pointer - Classic Tortoise Hare
    Time complexity : O(N)
    Space Complexity : O(1)

    Initialize both of the pointers at HEAD node. 
    And move SLOW pointer 1 step at a time while FAST pointer 2 step at a time.
    If there is a cycle, both pointers are bound to meet at a point.
    If FAST pointer reaches the end of the list, then there is NO CYCLE present.
*/


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};