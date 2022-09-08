// PROBLEM LINK
// https://leetcode.com/problems/subsets-ii/

/*
    Solution : Recursion (pick / not pick approach)
    Time complexity :  O(2^N) 
    Space Complexity : O(2^N)

    How to remove Duplicates Subsets?
    1. if you are choosing that val, then recurse with the immediate next position.
    2. if you are NOT choosing that val, then recurse with the next position which contains different value
*/


class Solution {
public:
    
    void subsetHelper(int ind, vector<int> &currVec, vector<int> &nums, vector<vector<int>> &ans){
        if(ind == nums.size()){
            ans.push_back(currVec);
            return;
        }
        
        int val = nums[ind];
        int indexWithNextVal = nums.size();
        for(int i=ind+1;i<nums.size();i++){
            if(val != nums[i]){
                indexWithNextVal = i;
                break;
            }
        }
        
        currVec.push_back(nums[ind]);
        subsetHelper(ind+1,currVec, nums, ans);
        currVec.pop_back();
            
        subsetHelper(indexWithNextVal,currVec, nums, ans);
    } 
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currVec;
        sort(nums.begin(), nums.end());
        subsetHelper(0,currVec ,nums, ans);
        return ans;
    }
};