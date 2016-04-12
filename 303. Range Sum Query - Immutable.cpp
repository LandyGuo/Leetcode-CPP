/*
303. Range Sum Query - Immutable 
Difficulty: Easy
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/
/**
 *思路：动态规划：sum[i,j] = sum[j]-sum[i] 
 */

class NumArray {
public:
    int *opt;
    NumArray(vector<int> &nums) {
        int length = nums.size();
        opt = new int[length+1]();
        for(int i = 1;i<=nums.size();i++)
            opt[i] = opt[i-1]+nums[i-1]; 
    }

    int sumRange(int i, int j) {
        return opt[j+1]-opt[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
