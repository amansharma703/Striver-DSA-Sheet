// PROBLEM 
// https://leetcode.com/problems/copy-list-with-random-pointer/


/*
    Solution 1 : Hashmap
    Time complexity : O(N) + O(N) 
    Space Complexity : O(N)

    Use Map to store node address of random node pointer and create a new copy linked list
    and in next tranversal add random pointer referencing from map to copy linked list

*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};