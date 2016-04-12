/*
26. Remove Duplicates from Sorted Array
Difficulty: Easy
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/
/**
 * pass2：
 *思路： 
 * 注意题意：给的数组是已经排好序的了，这也就意味着，如果跟前一个数不同，那么肯定也跟更前面的数不同
 * 1.p1指向当前需要放入与前一个不同的数的位置，p2指向当前已经处理的数(p1之前全部都是没有重复的数)
 * 2.如果p2与当前p1前一个数不同，那么p2就应该放到当前位置,否则p2后移，处理下一个数
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1)//数组长度<=1,肯定不会有重复的，直接返回长度
            return nums.size();
        int p1,p2;
        p1=1,p2=1;//将p1放在当前需要填充数的位置，p2从第二个数开始处理,数组中第一个数肯定是valid的
        while(p2<nums.size())
        {
            if(nums[p2]!=nums[p1-1])//p2与当前p1前一个数不同，那么p2就应该放到当前位置
                nums[p1++]=nums[p2++];
            else//相同，p2后移，处理下一个数
                p2++;
        }
        return p1;//p1之前的数都不相同，p1即为之前的不同数的长度
    }
};
