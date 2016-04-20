/*
35. Search Insert Position 
Difficulty: Medium
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
/*2nd pass
典型的二分查找问题：
二分查找，如果能找到，那么mid就是应该插入的元素位置；如果找不到，那么left位置就是应该插入的位置
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int right = nums.size()-1,left=0;
        int mid = (left+right)/2;
        while(left<=right)
        {
            if(nums[mid]== target)
                return mid;
            else if(nums[mid]>target)
                right=mid-1;
            else
                left = mid+1;
            mid = (left+right)/2;
        }
        return left;
    }
};
