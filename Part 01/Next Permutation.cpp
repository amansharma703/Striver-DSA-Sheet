// PROBLEM LINK
// https://leetcode.com/problems/next-permutation/

/*
    Approach 1 :  Optimal
    Time Complexity : O(N)
    Space Complexity : O(1)
    Step 1: Linearly traverse array from backward such that a[i] < a[i+1]. Store that index in a variable.

    Step 2: If the index value received from step 1 is less than 0. 
            This means the given input array is the largest lexicographical permutation.
            Hence, we will reverse the input array to get the minimum or starting permutation. 
            Linearly traverse array from backward. Find an index that has a value greater than the previously found index. 
            Store index another variable.
    
    Step 3: swap(a[ind1], a[ind2]);

    Step 4: reverse(ind+1 -> last);
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
};