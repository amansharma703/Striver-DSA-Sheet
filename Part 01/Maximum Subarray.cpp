// PROBLEM LINK
// https://leetcode.com/problems/maximum-subarray/

/*
    Approach 1 :  KADANE ALGORITHM
    Time Complexity : O(N)
    Space Complexity : O(1)
    
    At an index i, what can be the optimal ans upto this place? (storing this in SUM variable)
    Take this value and add with the previous optimal max sum value.
    Now compare SUM with maxSum, and update MAX_VAL appropriately.

    What if SUM < 0 after this current position, 
    it can't contribute any furthur to next iterations as it would make the overall sum less,
    so we do SUM = 0;
*/


class Solution {
    
  public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);
        int maxSum = INT_MIN, sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum += nums.at(i);
            
            maxSum = max(maxSum, sum);
            
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxSum;
    }
};