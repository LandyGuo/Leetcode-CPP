/*
221. Maximal Square 
Difficulty: Medium
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/
/*2nd pass
思路：
动态规划:opt[i][j] = min(opt[i-1][j-1],opt[i][j-1],opt[i-1][j])+1 if A[i][j]=='1' else 0


*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int rows = matrix.size(),cols =matrix[0].size();
        if(cols==0)
            return 0;
        //initialize
        vector<vector<int>>opt(rows,vector<int>(cols,0));
        int max_size=opt[0][0];
        for(int i=0;i<rows;i++)
        {
           opt[i][0] = (matrix[i][0]=='1')?1:0;
           max_size = max(max_size,opt[i][0]);
        }
        for(int i = 0;i<cols;i++)
        {
            opt[0][i] = matrix[0][i]=='1'?1:0;
             max_size = max(max_size,opt[0][i]);
        }
        //dynamic programming
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(matrix[i][j]=='0')
                    opt[i][j] =0;
                else
                   opt[i][j] = min(opt[i-1][j],min(opt[i][j-1],opt[i-1][j-1]))+1; 
                max_size = max(max_size,opt[i][j]);
            }
        }
        return max_size*max_size;
    }
};
