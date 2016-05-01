/*
330. Patching Array  
Difficulty: Medium
Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.
*/
//2nd pass
/*思路：
cur_range是个连续的范围表示[1,cur_range]
初始范围为cur_range = 0，当来一个nums[i]时，
若nums[i]<=cur_range+1,则cur_range = cur_range+nums[i];
若nums[i]>cur_range+1,则需要打个patch,patch值为cur_range+1时，可以将范围扩至最大:2*cur_range+1,然后扩大范围后再处理nums[i]
由于cur_range可能会很大，因此需要long long型
*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long cur_range = 0;//[1,cur_range]//注意：这个范围非常大，可能会溢出
        int i=0;
        int ret = 0;
        while(cur_range<n)
        {
            if((i<nums.size()&&nums[i]>cur_range+1)||i>=nums.size()) 
            {
                ret+=1;
                cur_range = 2*cur_range+1;
            }
            else
            {
                cur_range = cur_range+nums[i];
                i++;
            }
        }
        return ret;
    }
};
