// PROBLEM 
// https://leetcode.com/problems/powx-n/


/*
    Solution 1 : Bruteforce
    Time complexity : O(N^2) 
    Space Complexity : O(1)

    Nested loop to check for the pair
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                res.push_back(i);
                res.push_back(j);
                break;
            }
        }
        if (res.size() == 2)
            break;
        }
        return res;
    }
};


/*
    Solution 2 : Hash-Map
    Time complexity : O(N) 
    Space Complexity : O(N)

    Store current fetched nums in the hash-map. 
    Also while traversal check for (target - nums[i]) in the hashmap.
    If fetched, get its index and return.
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int temp;
            temp = target - nums[i];
            if (m.find(temp) != m.end()) {
                indices.push_back(m[temp]);
                indices.push_back(i);
                return indices;
            }
            m[nums[i]] = i;
        }
        return indices;
    }
};