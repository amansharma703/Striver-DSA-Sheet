// PROBLEM LINK
// https://leetcode.com/problems/permutations/

/*
    Solution : 
    Time complexity : O( N! * N )
    Space Complexity : O(1)
*/


class Solution {
public:
     void solve(vector<int>& nums, vector<vector<int>>& ans, int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=index; j<nums.size(); j++){
            swap(nums[index], nums[j]);
            solve(nums, ans, index+1); //recursive call
            swap(nums[index], nums[j]); //backtracking
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
    }
};