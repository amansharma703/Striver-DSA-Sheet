// PROBLEM 
// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

/*
    Solution : 
    Time complexity : O(NlongN) 
    Space Complexity : O(1)
*/


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int plat = 1, result = 1;
    	int i=1, j=0;
    	
    	while(i<n && j<n){
    	    if(arr[i] <= dep[j]){ //one more platform needed
    	        plat++;
    	        i++;
    	    }
    	    else{ //one platform can be reduced
    	        plat--;
    	        j++;
    	    }
    	    result = max(plat, result);
    	}
    	return result;
    }
};