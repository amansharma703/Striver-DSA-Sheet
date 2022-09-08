// PROBLEM LINK
// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

/*
    Solution : 
    Time complexity : O(N log N) + O(N) 
    Space Complexity : O(1)
*/


class Solution
{
    public:
    static bool com(Item a, Item b){
        double r1 = (double)a.value/(double)a.weight;
        double r2 = (double)b.value/(double)b.weight;
        return r1> r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, com);
        
        int curWeight =0;
        double finalVal = 0.0;
        
        for(int i=0;i<n;i++){
            if(curWeight + arr[i].weight <= W){
                curWeight += arr[i].weight;
                finalVal += arr[i].value;
            }
            else{
                int remain = W - curWeight;
                finalVal += (arr[i].value/ (double)arr[i].weight) * (double)remain;
                break;
            }
        }
        return finalVal;
        
    }
        
};