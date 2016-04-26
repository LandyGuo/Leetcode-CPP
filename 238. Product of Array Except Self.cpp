/*
238. Product of Array Except Self  
Difficulty: Medium
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

Subscribe to see which companies asked this question
*/
//2nd pass
/*
思路：
用两个数组分别存除了当前数以外的从左向右的乘积(arr1)和从右向左的乘积(arr2)
arr :1   2  3  4 
arr1:1   1  2  6
arr2:24  12 4  1
最终结果即为arr1*arr2;注意：arr2可以用一个单元存储，每次更新这个单元的值即可
因此空间复杂度为O(1)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int>res(len,0);
        res[0] = 1;
        for(int i=1;i<len;i++)
            res[i] = res[i-1]*nums[i-1];
        int cur = 1;
        for(int i=len-2;i>=0;i--)
        {
            cur*=nums[i+1];
            res[i] = res[i]*cur;
        }
        return res;
    }
};
