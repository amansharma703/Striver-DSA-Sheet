// PROBLEM 
// https://leetcode.com/problems/powx-n/


/*
    Solution 1 : Bruteforce
    Time complexity : O(N) 
    Space Complexity : O(1)

    Looping from 1 to n and keeping a ans(double) variable. Now every time your loop runs, multiply x with ans. At last, we will return the ans.  Gives TLE
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1.00000;
        long long int temp = n;
        if(n<0)
            temp = -n;
        long double result = x;
        for(int i=1;i<temp;i++){
            result = result*x;
        }
        if(n<0){
            return 1/result;
        }
        return result;
    }
};




/*
    Solution 1 : Optimized - Binary Exponentiation
    Time complexity : O(N) 
    Space Complexity : O(1)

    Initialize ans as 1.0  and store a duplicate copy of n i.e nn using to avoid overflow

    Check if nn is a negative number, in that case, make it a positive number.

    Keep on iterating until nn is greater than zero, now if nn is an odd power then multiply x with ans ans reduce nn by 1. Else multiply x with itself and divide nn by two.

    Now after the entire binary exponentiation is complete and nn becomes zero, check if n is a negative value we know the answer will be 1 by and.
*/


class Solution {
public:
    double myPow(double x, int n) {
      double ans = 1.0;
      long long nn = n;
      if (nn < 0) nn = -1 * nn;
      while (nn) {
        if (nn % 2) {
          ans = ans * x;
          nn = nn - 1;
        } else {
          x = x * x;
          nn = nn / 2;
        }
      }
      if (n < 0) ans = (double)(1.0) / (double)(ans);
      return ans;
    }
};