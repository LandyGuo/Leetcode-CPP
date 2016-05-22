/*
45. Jump Game II 
Difficulty: Hard
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/
//2nd pass
/*
思路1：
走到当前步长内，为下一步步长铺路，当超过当前步长范围时，步长就加1，将下一步铺的路拿来用
last是当前步长，cur是下一步步长铺到的位置
思路2：
动态规划：从后往前动态规划，找到达数组的最小步数
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int cur=0,last=0;
        int step = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>last)
            {
                last = cur;//超过last跳到cur
                step++;
            }
            cur = max(nums[i]+i,cur);//每步都更新cur
        }
        return step;
    }
};
