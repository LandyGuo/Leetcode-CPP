/*
213. House Robber II   
Difficulty: Medium
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
/*2nd pass
思路：因为首尾两个House相邻，因此这2个一定是互斥的，如果抢了第一个，一定不能抢最后一个；如果抢了最后一个，一定不能抢第一个；
这样就化解为两个第一个问题，求这两种情况的最大值即可。
需要注意的是：需要将只有一个元素的这种情况单独分离出来讨论
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size()==1)//将只有一个元素的这种情况单独分离出来讨论
            return nums[0];
        //去掉最后一个元素
        vector<int> nums_no_last(nums.begin(),nums.end()-1);
        vector<int> nums_no_begin(nums.begin()+1,nums.end());
        return max(rob1(nums_no_last),rob1(nums_no_begin));
        
    }
    
    
    int rob1(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int>opt(nums.size()+1,0);
        opt[1] = nums[0];
        for(int i=2;i<opt.size();i++)
            opt[i] = max(opt[i-2]+nums[i-1],opt[i-1]);
        return opt[opt.size()-1];
    }
};
