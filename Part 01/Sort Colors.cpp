// PROBLEM LINK 
// https://leetcode.com/problems/sort-colors/


/*
    Approach 1 : Simply sort it
    Time Complexity : O(NlogN)
    Space Complexity : O(1)
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
       sort(nums.begin(), nums.end());
    }
};



/*
    Approach 2 : Use Count Sort Technique
    Time Complexity : O(2N)
    Space Complexity : O(1)
    
    1. Take 3 variables to maintain the count of 0, 1 and 2.
    2. Travel the array once and increment the corresponding counting variables
    3. In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’, the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count_0 = 0;
        int count_1 = 0; 
        int count_2  = 0;
        for(int i =0; i< nums.size(); i++){
            if(nums[i] == 0){
                count_0++;
            }else if (nums[i] == 1){
                count_1++;
            }else if (nums[i] ==2 ){
                count_2++;
            }
            
         }
        for(int i =0; i< count_0; i++){
            nums[i] =0;
        }
        for(int i =count_0; i< (count_1 + count_0); i++){
            nums[i] =1;
        }
        for(int i =(count_1 + count_0); i< nums.size(); i++){
            nums[i] =2;
        }
        
    }
};


/*
    Approach 3 : Using 3 pointers
    Time Complexity : O(N)
    Space Complexity : O(1)
    
    At each stage

    1. 0 to low - 1 -> all zeroes
    2. high + 1 to N - 1 -> all twos
    3, rest in between -> all 1's. 

    If we fetch 0's or 2's here, then interchange at low pointer or high pointer.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0; 
        int high = nums.size()-1;
        int mid =0;
        
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};