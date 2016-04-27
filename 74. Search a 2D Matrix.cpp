/*
74. Search a 2D Matrix  
Difficulty: Medium
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/
//思路：利用二分查找，查找第一个比Target大的值(left)，确定行；然后再在该行二分查找Target小的值，看能否找到
//需要注意的是:二分查找l的位置就是第一个比target大的值，也是该target应该插入的位置
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int rows = matrix.size(),cols = matrix[0].size();
        //search row
        int l = 0,r=rows-1,mid=l+(r-l)/2;
        while(l<=r)
        {
            if(matrix[mid][cols-1]==target)
                return true;
            else if(matrix[mid][cols-1]>target)
                r = mid-1;
            else
                l = mid+1;
            mid=l+(r-l)/2;
        }
        //l的位置就是第一个比target大的位置,也就是target应该插入的位置
        if(l>rows-1)
            return false;
        cout<<l<<endl;
        //search cols
        int left = 0,right=cols-1,middle = left+(right-left)/2;
        while(left<=right)
        {
            if(matrix[l][middle]==target)
                return true;
            else if(matrix[l][middle]>target)
                right = middle-1;
            else
                left = middle+1;
            middle = left+(right-left)/2;
        }
        return false;
        
    }
};
