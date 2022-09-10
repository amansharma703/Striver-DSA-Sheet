// PROBLEM LINK
// https://leetcode.com/problems/combination-sum/

/*
    Solution : Recursion (pick / not pick approach)
    Time complexity :  O(2^t * k), where t is the target, k is the average length
    Space Complexity : O(k*x), k is the average length and x is the no. of combinations
*/



class Solution {
    private:
        void findCombinations(int index, vector<int> arr, int target, vector<vector<int>> &ans, vector<int> &ds){
            if(index == arr.size()){
                if(target==0){
                    ans.push_back(ds);
                }
                return;
            }
            if(arr[index] <= target ){
                ds.push_back(arr[index]);
                findCombinations(index, arr, target-arr[index], ans, ds);
                ds.pop_back();
            }
            findCombinations(index+1, arr, target, ans, ds);
        }
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> ds;
            findCombinations(0, candidates, target, ans, ds);
            return ans;
        }
};