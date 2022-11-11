// PROBLEM LINK
// https://www.codingninjas.com/codestudio/problems/queue-using-array-or-singly-linked-list_2099908

/*
    Solution : 
    Time complexity : O(N)
    Space Complexity : O(N)
*/



#include <bits/stdc++.h> 
class Queue {
    vector<int> vec;
public:
    Queue() {

    }

    bool isEmpty() {
        // Implement the isEmpty() function
        if(vec.size() > 0) return false;
        return true;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        vec.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
       if (vec.size() > 0) {
           int x = vec[0];
            vec.erase(vec.begin());
           return x;
       }
        return -1;
    }

    int front() {
        // Implement the front() function
        if (vec.size() > 0) {
           return vec[0];
        }
        return -1;
    }
};