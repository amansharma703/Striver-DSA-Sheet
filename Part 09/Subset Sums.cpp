// PROBLEM LINK
// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

/*
    Solution : Recursion (pick / not pick approach)
    Time complexity :  O(2^N) + O(N LogN ) 
    Space Complexity : O(2^N)
*/


class Solution
{
public:

    void subsetSumsHelper(int ind, vector<int> &arr, int n, vector<int> &ans, int sum){
        if(ind==n){
            ans.push_back(sum);
            return;
        }
        subsetSumsHelper(ind+1, arr, n, ans, sum + arr[ind]);
        subsetSumsHelper(ind+1, arr, n, ans, sum);
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        vector<int> ans;
        subsetSumsHelper(0, arr,n, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};