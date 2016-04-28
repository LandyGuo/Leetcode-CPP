/*
53. Maximum Subarray   
Difficulty: Medium
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/
/*2nd pass
        经典问题：最大连续子数组和问题，标准的动态规划
        思路：动态规划;
        opt[i] = max(opt[i-1]+A[i],A[i])
注意：opt[i]表示以i为结尾的最大子数组和，因此整个数组的最大子数组和需要将opt遍历一遍，取最大值
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>opt(nums.size()+1,0);
        for(int i=1;i<opt.size();i++)
            opt[i] = max(opt[i-1]+nums[i-1],nums[i-1]);
        int ret = INT_MIN;
        for(int i=1;i<opt.size();i++)
            ret = max(ret,opt[i]);
        return ret;
    }
};
