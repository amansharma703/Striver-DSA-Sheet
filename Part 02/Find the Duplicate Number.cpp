// PROBLEM 
// https://leetcode.com/problems/find-the-duplicate-number/


/*
    Solution 1 : Bruteforce
    Time complexity : O(NlogN) [for using the sort function] + O(N) [for traversing the interval] = O(NlogN)
    Space Complexity : O(1)

    1. Sort the array and compare consecutive elements.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i] == nums[i+1])
                return nums[i];
        }
        return -1;
    }
};



/*
    Solution 2 : Use Map or Vector
    Time complexity : O(N)  [for traversing the interval] 
    Space Complexity : O(1)

    1. Use Map / another vector to store the count of elements.
*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size()+1;
        int arr[n] ;
        memset (arr, 0, sizeof(arr));
        for(int  i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(arr[i] > 1){
                return i;
            }
        }
        return -1;
    }
};



/*
    Solution 3 :
    Time complexity : O(N)  
    Space Complexity : O(1)

    We know that array elements are from 1 to N only. And there are N + 1 elements in total.
    What if we can arrange 1,2,3...,N to their respective index 1,2,3,...,N etc.
    Then Index 0 would contain the duplicate one.

    Algo to do this,
    Take nums[0] and nums[nums[0]].
    if equal, this is the duplicate one.
    Else, swap them and repeat the whole process again until found.

    Why this works?
    LETS nums[0] = 2 and nums[nums[0]] = nums[2] = 3,
    So zeroth index contains 2 and second index contains 3. After swapping index 2 contains 2.
    Likewise, we will be repeating the process, providing each index with its equivalent number.
    LETS nums[0] = 4 and nums[nums[0]] = nums[4] = 4,
    So both location having same number, we are certain that this is the duplicate element.
*/



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(true){
            if(nums[0] == nums[nums[0]]){
                return nums[0];
            }else{
                swap(nums[0], nums[nums[0]]);
            }
        }
        return -1; // never reached
    }
};




/*
    Solution 4 : Tortoise Hare Variation
    Time complexity : O(N)  
    Space Complexity : O(1)

    Algo similar to finding the intersection point in a Linked List Cycle
*/



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int tortoise = nums[0];
        int hare = nums[0];
        
        do{
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }while(tortoise != hare);
        
        tortoise = nums[0];
        
        while(tortoise != hare){
            hare = nums[hare];
            tortoise = nums[tortoise];
        }
        
        return hare;
    }
};