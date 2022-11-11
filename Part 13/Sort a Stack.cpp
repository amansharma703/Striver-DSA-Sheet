// PROBLEM LINK
// https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275

/*
    Solution : 
    Time complexity : O(N)
    Space Complexity : O(N)
*/

#include <bits/stdc++.h> 
void sortStack(stack<int> &stack)
{
    vector<int> vec;
    while(!stack.empty()){
        int x = stack.top();
        vec.push_back(x);
        stack.pop();
    }
    sort(vec.begin(), vec.end());
    for(auto x : vec){
         stack.push(x);
    }
}