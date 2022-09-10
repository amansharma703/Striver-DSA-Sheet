// PROBLEM LINK
// https://leetcode.com/problems/combination-sum-ii/

/*
    Solution : Recursion (pick / not pick approach)
    Time complexity :  O(2^N)
    Space Complexity : O(2^N)
*/

class Solution {
    private:
        void findCombinations(int index, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &ds){
            if(target==0){
                    ans.push_back(ds);
                    return ;
            }
            for(int i=index;i<arr.size();i++){
                if(i>index && arr[i] == arr[i-1]) continue;
                if(arr[i]>target) break;
                ds.push_back(arr[i]);
                findCombinations(i+1, arr, target-arr[i], ans, ds);
                ds.pop_back();
            }            
            
        }
    public:   
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            vector<int> ds;
            findCombinations(0, candidates, target, ans, ds);
            return ans; 
    }
};