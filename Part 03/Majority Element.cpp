// PROBLEM 
// https://leetcode.com/problems/majority-element/


/*
    Solution 1 : Bruteforce
    Time complexity : O(NlogN) 
    Space Complexity : O(1)

   Sort and return the middle element.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
		
        sort(nums.begin(),nums.end());
		
        return nums[n/2];
    }
};



/*
    Solution 2 : HashMap
    Time complexity : O(N) 
    Space Complexity : O(N)

   Use hashmap to store the frequency.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> a;
        for(int i:nums)
            a[i]++;
        int maxval=nums[0];
        for(auto x:a)
        {
            if(x.second>a[maxval])
                maxval=x.first;
        }
        return maxval;
    }
};



/*
    Solution 3 : Boyer - Moore Voting Algo
    Time complexity : O(N) 
    Space Complexity : O(1)


    If we had some way of counting instances of the majority element as +1 
    and instances of any other element as −1, 
    summing them would make it obvious that the majority element is indeed the majority element.

    Solution - Track CURRENT number and its COUNT occurence.
    If CURRENT == nums[i], COUNT++
    Else COUNT--.
    What if COUNT == 0, then clearly the previously tracked number cannot be the greatest, 
    knowing till this point. Update CURRENT with nums[i].
*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int var = nums[0];
        int varCnt = 1;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(var == nums[i]){
                varCnt++;
            }else{
                varCnt--;
                if(varCnt == 0){
                    var = nums[i];
                    varCnt = 1;
                }
            }
        }
        
        return var;
    }
};