// PROBLEM LINK
// https://www.codingninjas.com/codestudio/problems/1112581

/*
    Solution : BruteForce
    Time complexity : O(N^2)
    Space Complexity : O(N)
*/


vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> vec;
    for(int i=0; i< n; i++){
        int find = false;
        for(int j=i; j< n; j++){
            if(arr[j] < arr[i]){
                find = true;
                vec.push_back(arr[j]);
                break;
            }
        }
        if(!find){
            vec.push_back(-1);
        }
    }
    return vec;
}



/*
    Solution : Optimal
    Time complexity : O(N)
    Space Complexity : O(N) + O(N)
*/


#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    st.push(-1);
    vector<int> vec(n);
    for(int i= n-1; i>= 0; i--){
        int curr = arr[i];
        while(st.top() >= curr){
            st.pop();
        }
        vec[i] = st.top();
        st.push(curr);
    }
    return vec;
}