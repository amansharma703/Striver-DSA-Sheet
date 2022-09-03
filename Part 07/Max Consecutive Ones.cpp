// PROBLEM 
// https://leetcode.com/problems/max-consecutive-ones/


/*
    Solution : 
    Time complexity : O(N)
    Space Complexity : O(1)

    Traverse and check for the maximum consecutive 1 sequence.
*/.

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOne = 0;
        int cnt = 0;
        for(int i=0; i<nums.size();++i){
            if(nums[i] == 1){
                cnt++;
            }else{
                maxOne = max(maxOne, cnt);
                cnt = 0;
            }
        }
        
        maxOne = max(maxOne, cnt);
        return maxOne;
    }
};