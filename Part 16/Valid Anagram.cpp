// PROBLEM LINK
// https://leetcode.com/problems/valid-anagram/

/*
    Solution : 
    Time complexity : O(N)
    Space Complexity : O(N)
*/


class Solution {
public:
    bool isAnagram(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        unordered_map<char, int> mp;

        for(int i=0; i<s1.length();i++){
            mp[s1[i]]++;
            mp[s2[i]]--;
        }

        for(auto x : mp){
            if(x.second !=0) return false;
        }
        return true;
    }
};