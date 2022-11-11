// PROBLEM LINK
// https://leetcode.com/problems/valid-parentheses/description/

/*
    Solution : 
    Time complexity : O(N)
    Space Complexity : O(N)
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char temp;

        for(int i=0; i< s.size(); i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                st.push(s[i]);
                continue;
            }
            if(st.empty()) return false;
            switch(s[i]){
                case '}': 
                    temp = st.top();
                    if(temp == '[' || temp == '(') return false;
                    st.pop();
                    break;
                case ']': 
                    temp = st.top();
                    if(temp == '{' || temp == '(') return false;
                    st.pop();
                    break;
                case ')': 
                    temp = st.top();
                    if(temp == '[' || temp == '{') return false;
                    st.pop();
                    break;
            }
        }
        return st.empty();
    }
};