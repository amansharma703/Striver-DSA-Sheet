// PROBLEM LINK
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
    Approach 1 :  BruteForce
    Time Complexity : O(N^2)
    Space Complexity : O(1)
    
    We can simply use 2 loops and track every transaction and maintain a variable maxPro to contain the max value among all transactions.

    1. Use a for loop of ‘i’ from 0 to n.
    2. Use another for loop of j from ‘i+1’ to n.
    3. If arr[j] > arr[i] , take the difference and compare  and store it in the maxPro variable.
    4. Return maxPro.
*/

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
  int maxPro = 0;
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] > arr[i]) {
        maxPro = max(arr[j] - arr[i], maxPro);
      }
    }
  }
  return maxPro;
}

int main() {
  vector<int> arr = {7,1,5,3,6,4};
  int maxPro = maxProfit(arr);
  cout << "Max profit is: " << maxPro << endl;
}



/*
    Approach 2 : Optimal
    Time Complexity : O(N)
    Space Complexity : O(1)

   Greedily store the minimum one and choose the maximum one present after the cur minimum.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n= prices.size();
        int minPrice = INT_MAX;
        int ans=0;
        
        for(int i=0; i<n; i++){
            minPrice = min(minPrice , prices[i]);
            ans = max(ans, prices[i]- minPrice );
        }
        
        return ans;
    }
};