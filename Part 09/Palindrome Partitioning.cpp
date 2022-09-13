// PROBLEM LINK
// https://leetcode.com/problems/palindrome-partitioning/

/*
    Solution : 
    Time complexity : O( (2^n) *k*(n/2) )
    Space Complexity : O(k * x)

    k : k is the average length of the list of palindromes
    x : no of palindromes list
*/


class Solution {
public:
    void helper(int ind, string s ,vector<string> &path ,vector<vector<string>> &ans){
        if(ind == s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=ind;i<s.size();++i){
            if(isPalinDrome(s, ind, i)){
                path.push_back(s.substr(ind, i-ind + 1));
                helper(i+1, s, path, ans);
                path.pop_back();
            }
        }
    }
    
    bool isPalinDrome(string s , int start, int end){
        while(start<=end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        helper(0,s,path, ans);
        return ans;
    }
};