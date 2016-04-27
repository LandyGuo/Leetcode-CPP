/*
268. Missing Number   
Difficulty: Medium
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/
//2nd pass
/*思路：
将i位置上的数与Nums[i]位置上的数交换，如果在合理范围内就交换；这样尽量保证nums[i]放到第i个位置上；
每次交换至少能保证1个数放到合适的位置上，这样交换n次就能将所有有合适位置的数都放到合适的位置上，然后遍历一遍，
遇到第一个nums[i]!=i的数时，就返回
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int target_pos= nums[i];
            while(target_pos>=0&&target_pos<nums.size()&&nums[target_pos]!=nums[i])
            {
                swap(nums[i],nums[target_pos]);
                target_pos= nums[i];
            }
        }
        int res = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(i!=nums[i])
            {
                res = i;
                break;
            }
        }
        return res;
    }
};
