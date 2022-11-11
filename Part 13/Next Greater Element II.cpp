// PROBLEM LINK
// https://leetcode.com/problems/next-greater-element-ii/

/*
    Solution : 
    Time complexity : O(N*N)
    Space Complexity : O(N)
*/


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> vec;
        for(int i=0; i<nums.size() ; i++){
            int find = false;
            for(int j=i ; j< (nums.size() + i); j++){
                int temp = j;
                if(j>= nums.size()){
                    temp = j %nums.size();
                }
                if(nums[temp] > nums[i]) {
                    find = true;
                    vec.push_back(nums[temp]);
                    break;
                }
               
            }
            if(!find){
                vec.push_back(-1);
            }
        }
        return vec;
    }
};