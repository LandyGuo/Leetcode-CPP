/*
62. Unique Paths 
Difficulty: Medium
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/
/*2nd pass
思路：
    动态规划:
    opt[i][j] = opt[i-1][j]+opt[i][j-1]
    注意初始化条件：第一行和第一列全都初始化为1，因为都只有一种走法
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>opt(m,vector<int>(n,1));
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                opt[i][j] = opt[i-1][j]+opt[i][j-1];
            }
        }
        return opt[m-1][n-1];
    }
};
