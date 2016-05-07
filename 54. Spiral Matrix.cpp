/*
54. Spiral Matrix  
Difficulty: Medium
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/
//2nd pass
/*
思路：按：
row = t,       col:[l,r]
row =[t+1,b],  col:r
row =b      ,  col:[r-1,l]
row =[b-1,t+1],col:l
的方法：
注意循环次数为matrix中总元素数量rows*cols,注意每次循环都需要判断
*/
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return vector<int>();
		int m = matrix.size(), n = matrix[0].size();
		vector<int> ret(m*n, 0);
		int l = 0, r = n - 1, t = 0, b = m - 1;
		int cnt = 0;
		while (cnt < m*n)
		{
			for (int i = l; cnt < m*n&&i <= r; i++)//每次循环都需要判断，避免单行或单列的情况
				ret[cnt++] = matrix[t][i];
			for (int i = t + 1; cnt < m*n&&i <= b; i++)//每次循环都需要判断
				ret[cnt++] = matrix[i][r];
			for (int i = r - 1; cnt < m*n&& i >= l; i--)//每次循环都需要判断
				ret[cnt++] = matrix[b][i];
			for (int i = b - 1; cnt < m*n&& i >= t + 1; i--)//每次循环都需要判断
				ret[cnt++] = matrix[i][l];
			l += 1, r -= 1, t += 1, b -= 1;
		}
		return ret;
	}
};
