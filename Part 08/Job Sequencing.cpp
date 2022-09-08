// PROBLEM LINK
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

/*
    Solution : 
    Time complexity : O(N log N) + O(N*M) 
    Space Complexity : O(M)
*/


class Solution 
{
    public:
    static bool comparision(Job a , Job b){
        return a.profit > b.profit;        
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr +n, comparision);
        int maxi = arr[0].dead;
        for(int i=0;i<n;++i){
            maxi = max(maxi, arr[i].dead);
        }
        
        int slot[maxi+1];
        
        for(int i=0;i<= maxi;i++){
            slot[i] = -1;
        }
        
        int cntJob=0, jobProfit=0;
        
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j]== -1){
                    slot[j] = i;
                    cntJob++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {cntJob, jobProfit};
    } 
};