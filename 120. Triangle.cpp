/*
120. Triangle
Difficulty: Medium
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
//2nd pass
/*思路：动态规划：
opt[i][j] = min(opt[i+1][j],opt[i+1][j+1])+A[i][j]
第i行的值从第i+1行中取其相邻的2个数中最小的值与其叠加，因此每次都会比上一行少一个数，到最高层就只剩一个数
由于opt[i][j]依赖于opt[i+1][j]和opt[i+1][j+1]的值，因此当前行依赖下一行的值，因此从下往上，从前往后更新即可，只用O(n)空间
从下往上好处是：长度只会缩减，不用判断边界条件
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int levels = triangle.size();
        vector<int> opt =triangle[levels-1] ;
        for(int i=levels-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                opt[j] = min(opt[j],opt[j+1])+triangle[i][j];
            }
        }
        return opt[0];
    }
};
