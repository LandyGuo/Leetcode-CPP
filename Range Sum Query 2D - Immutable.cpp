/*
304. Range Sum Query 2D - Immutable  
Difficulty: Medium
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/
//2nd pass
//思路：转换为多个一维的动态规划
class NumMatrix {
private:
    vector<vector<int>> opt;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.empty())
            return;
        int rows = matrix.size(),cols = matrix[0].size();
        opt = vector<vector<int>>(rows,vector<int>(cols+1,0));
        for(int row=0;row<rows;row++)
        {
            for(int col=1;col<cols+1;col++)
            {
                opt[row][col] = opt[row][col-1]+matrix[row][col-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int cur =row1;cur<=row2;cur++)
            sum +=(opt[cur][col2+1]-opt[cur][col1]);
        return sum;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
