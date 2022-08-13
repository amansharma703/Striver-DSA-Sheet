// PROBLEM 
// https://leetcode.com/problems/merge-sorted-array/


/*
    Solution 1 : Bruteforce
    Time complexity : O(NlogN) [for using the sort function] + O(N) [for traversing the interval] = O(NlogN)
    Space Complexity : O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<m + n;i++){
            nums1[i] = nums2[i-m];
        }
        sort(nums1.begin(), nums1.end());
    }
};




/*
    Solution 2 : Two Pointer
    Time complexity : O(N + M) 
    Space Complexity : O(1)

    1. Begin from last index of both array, compare two elements from both array, 
    2. Overwrite in the last available position of nums1 (as it is meant to be INPLACE).
*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int itrA = m - 1;
        int itrB = n - 1;
        int itr = m + n - 1;
        while(itrA >= 0 && itrB >= 0){
            if(nums1[itrA] > nums2[itrB]){
                nums1[itr] = nums1[itrA];
                itr--;
                itrA--;
            }else{
                nums1[itr] = nums2[itrB];
                itr--;
                itrB--;
            }
        }
        
        while(itrB >= 0){
            nums1[itr] = nums2[itrB];
            itr--;
            itrB--;
        }
        
    }
};