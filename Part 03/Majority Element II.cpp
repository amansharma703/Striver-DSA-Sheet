// PROBLEM 
// https://leetcode.com/problems/majority-element-ii/


/*
    Solution 1 : Bruteforce
    Time complexity : O(N^2) 
    Space Complexity : O(1)

   Simply count the no. of appearance for each element.
   whenever you find the count of an element greater than N/3 times.
   Add it to Vector
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int uprange = ceil(nums.size()/3);  
        sort(nums.begin(),nums.end());

        vector<int> res;
        for(int i=0; i<n; i++)
        {
            int cnt = count(nums.begin(), nums.end(), nums[i]);
            if(cnt>uprange)
            {
                res.push_back(nums[i]);
                i+=cnt-1;
            }
        }
        return res;
    }
};


/*
    Solution 2 : HashMap
    Time complexity : O(N) 
    Space Complexity : O(N)

   Use hashmap to store the frequency.
   Traverse map and whenever you find the count of an element greater than N/3 times.
   Add it to vector.
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int uprange = ceil(nums.size()/3);        
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        int maxval=nums[0];
        for(auto x:mp)
        {
            if(x.second > uprange){
                v.push_back(x.first);
            }
        }
        return v;
    }
};