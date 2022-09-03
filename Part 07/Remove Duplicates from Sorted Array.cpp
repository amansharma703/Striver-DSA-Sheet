// PROBLEM 
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/


/*
    Solution 1 : Use Vector
    Time complexity : O(N)
    Space Complexity : O(N)

    Use Vector to store unique element from the array and return its length;
*/.


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> temp(nums.size());
        temp[0] = nums[0];
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (temp[res - 1] != nums[i]) {
                temp[res] = nums[i];
                res++;
            }
        }
        for (int i = 0; i < res; i++) {
            nums[i] = temp[i];
        }
        return res;
    }
};




/*
    Solution 1 : Optimal
    Time complexity : O(N)
    Space Complexity : O(1)

    Traverse and replace the newmost non - duplicate value at the leftmost available position.
    Update pointer accordingly.

*/.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int res = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[res-1]){
                nums[res] = nums[i];
                res++;
            }
        }
        return res;
    }
};