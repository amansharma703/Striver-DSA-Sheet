// PROBLEM LINK
// https://leetcode.com/problems/set-matrix-zeroes/

/*
    Solution 1
    Time Complexity : O(N*M)
    Space Complexity : O(2*N*M) ~ O(N*M) in Worst Case
    Let's create a vector of pair , and store the indexes whose vlaue is Zero as pair in vector.
    Finally traverse the pairs in vector, and set zeroes to the entire respective rows and columns.
*/

class Solution
{
private:
    void helper(vector<vector<int>> &matrix, int x, int y)
    {
        for (int i = 0; i < matrix[0].size(); ++i)
        {
            matrix[x][i] = 0;
        }
        for (int j = 0; j < matrix.size(); ++j)
        {
            matrix[j][y] = 0;
        }
    }

public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    pairs.push_back({i, j});
                }
            }
        }
        for (auto p : pairs)
        {
            helper(matrix, p.first, p.second);
        }
    }
};

/*
    Solution 2
    Time Complexity : O(N*M)
    Space Complexity : O(1)
    Instead of marking on an additional space, use the INPLACE 1st row and 1st column for that purpose.
    And take one variable for marking 1st row and 1st column.
*/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0] == 0)
                col0 = 0;
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 1; --j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if (col0 == 0)
                matrix[i][0] = 0;
        }
        return;
    }
};