/*
152. Maximum Product Subarray  
Difficulty: Medium
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
/*2nd pass
思路：
因为最大乘积遇到-1时会进行翻转，可能最大变最小，最小变最大；因此需要维护2个数组，opt_max保存以当前节点为终点的连续最大乘积，opt_min保存以当前节点为终点的连续最小乘积
到当前数时最大的乘积一定在:
opt_max = max(opt_max[i-1]*nums[i],opt_min[i-1]*nums[i],nums[i])
opt_min = min(opt_max[i-1]*nums[i],opt_min[i-1]*nums[i],nums[i])
然后遍历opt_max从中找最大即可(注意不要包含最初初始化为1的值)-------之所以要遍历是因为这个最大至少当前节点的最大乘积，而不是整个数组的最大乘积
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>opt_max(nums.size()+1,1),opt_min(nums.size()+1,1);
        for(int i=1;i<opt_max.size();i++)
        {
            opt_max[i] = max(max(opt_max[i-1]*nums[i-1],opt_min[i-1]*nums[i-1]),nums[i-1]);
            opt_min[i] = min(min(opt_max[i-1]*nums[i-1],opt_min[i-1]*nums[i-1]),nums[i-1]);
        }
        int ret=INT_MIN;
        for(int i=1;i<opt_max.size();i++)
            ret = max(ret,opt_max[i]);
        return ret;
    }
};
