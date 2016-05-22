/*
55. Jump Game 
Difficulty: Medium
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
//2nd pass
/*思路：
每到一步，根据当前步所能到的范围的下标，更新最大能到的下标；如果有某个下标>最大可达的下标,那么就说明没有办法到达
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;
        int max_reach = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(i<=max_reach)
                max_reach = max(max_reach,i+nums[i]);
            else
                return false;
        }
        return true;
    }
};
