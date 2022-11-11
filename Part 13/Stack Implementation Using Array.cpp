// PROBLEM LINK
// https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209

/*
    Solution : 
    Time complexity : O(N)
    Space Complexity : O(N)
*/

#include <bits/stdc++.h> 
// Stack class.
class Stack {
    vector<int> vec;
    int t;
    int capacity;
    
public:
    
    Stack(int capacity) {
        // Write your code here.
        vec.resize(capacity);
        this->capacity = capacity;
        t=-1;
    }

    void push(int num) {
        // Write your code here.
        t++;
        vec[t] = num;
    }

    int pop() {
        // Write your code here.
        if(t == -1 ) return -1;
        int x = vec[t];
        t--;
        return x;
    }
    
    int top() {
        // Write your code here.
        if(t == -1 ) return -1;
        return vec[t];
    }
    
    int isEmpty() {
        // Write your code here.
        if(t == -1) return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(t == vec.size()-1) return 1;
        return 0;
    }
    
};