/*
283. Move Zeroes  
Difficulty: Easy
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
/*2nd pass:
2 pointers:p1作为主指针(负责找0的位置)，p2作为辅助指针(负责从p1之后找第一个不为0的元素)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1=0,p2=0;
        while(p1<nums.size())
        {
            if(nums[p1]!=0)
                p1++;
            else
            {
                p2 = p1+1;
                while(p2<nums.size()&&nums[p2]==0)p2++;
                if(p2==nums.size()) break;
                nums[p1] = nums[p2];
                nums[p2] = 0;
                p1++;
            }
        }
    }
};
