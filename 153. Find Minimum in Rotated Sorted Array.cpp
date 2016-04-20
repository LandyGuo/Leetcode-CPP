/*
153. Find Minimum in Rotated Sorted Array   
Difficulty: Medium
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
/*2nd pass
no duplicates in the array
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len==1)
            return nums[0];
        if(nums[len-1]>nums[0])//数组没有旋转，返回最小值
            return nums[0];
        int left = 0,right = len-1,mid = (left+right)/2;
        while(left+1!=right)
        {
            if(nums[mid]>nums[left])//left向左侧最高点逼近，因为没有重复，不用考虑相等的情况
                left = mid;
            else if(nums[mid]<nums[right])//right向右侧最低点逼近，因为没有重复，不用考虑相等的情况
                right = mid;
            mid = (left+right)/2;
        }
        return nums[right];
    }
};
