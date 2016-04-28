/*
198. House Robber  
Difficulty: Easy
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

Subscribe to see which companies asked this question
*/
/*2nd pass
思路：opt[i] = max(opt[i-2]+A[i],opt[i-1])

*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int>opt(nums.size()+1,0);
        opt[1] = nums[0];
        for(int i=2;i<opt.size();i++)
            opt[i] = max(opt[i-2]+nums[i-1],opt[i-1]);
        return opt[opt.size()-1];
    }
};
