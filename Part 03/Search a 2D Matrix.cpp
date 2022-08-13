// PROBLEM 
// https://leetcode.com/problems/search-a-2d-matrix/


/*
    Solution 1 : Bruteforce
    Time complexity : O(N*M) 
    Space Complexity : O(1)

   Just Linear scan and return true if element found otherwise return false
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       // m = total rows
		// n = total columns
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }
};


/*
    Solution 2 : Optimized
    Time complexity : O(N+M) 
    Space Complexity : O(1)

   Start from Top - Right Corner.
    At any position,
    if arr[i][j] is less than required number, go down.
    if arr[i][j] is more than required number, go left.
	Observe this diagrammatically why!

    If anywhere between target is fetched,, return true. Else return false.
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // m = total rows
		// n = total columns
        int m = matrix.size();
        int n = matrix[0].size();
        
		// Start from top-right corner 
        int row = 0, col = n-1;
        
		// Traverse the matrix
        while(row < m && col >= 0)
        {
			// If target found
            if(matrix[row][col] == target)
                return true;
            
			// If target is smaller than current element - decrement col 
            if(matrix[row][col] > target)
                col--;
				
			// If target is greater than current element - increment row
            else
                row++;
        }
        
		// Target not found
        return false;
    }
};