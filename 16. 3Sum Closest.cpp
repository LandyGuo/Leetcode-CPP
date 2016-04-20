/*
16. 3Sum Closest   
Difficulty: Medium
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Subscribe to see which companies asked this question
*/
/*思路：2nd pass
确定第一个数，转化为2-sum问题，在2-sum中采用两边夹逼法，每次向target值靠近，并更新res
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int curNum=0,res=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size();i++)
        {
            curNum = nums[i];
            int curTarget = target-curNum;
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                res = abs(res-target)>(abs(curNum+nums[j]+nums[k]-target))?(curNum+nums[j]+nums[k]):res;
                if(nums[j]+nums[k]>curTarget)
                    k--;
                else if(nums[j]+nums[k]<curTarget)
                    j++;
                else
                    return target;   
            }
        }
        return res;
    }
};
