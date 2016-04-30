/*
300. Longest Increasing Subsequence  
Difficulty: Medium
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/
//2nd pass
/*
思路：opt[i] 表示以A[i]结尾的最长递增子序列的长度
opt[i] = max(opt[j]+1)  (0<=j<i)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int>opt(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    opt[i] = max(opt[i],opt[j]+1);
            }
        }
        int ret= 1;//最小递增序列的长度就是只包含它本身一个元素，长度为1
        for(int x:opt)
            ret = max(ret,x);
        return ret;
    }
};
