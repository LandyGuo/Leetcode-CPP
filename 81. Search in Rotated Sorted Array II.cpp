/*
81. Search in Rotated Sorted Array II 
Difficulty: Medium
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
/*
思路：
比如：｛1，3，1，1，1，1｝
如果A[start] <= A[mid] 条件就不能确定[start mid]区间为递增有序序列，我们就把该条件分成两个子条件：
A[start] < A[mid] 则 [start mid]区间为递增有序序列
A[start] = A[mid] 则[start mid]区间不能确定，那就start++，往下一步看看即可
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        int mid = left+(right-left)/2;
        while(left<=right)
        {
            if(nums[mid]==target)return true;
            else if(nums[mid]>nums[left])//中间元素>左边元素，[left,mid]是一个递增区间
            {
                if(target>=nums[left]&&target<=nums[mid])
                    right = mid-1;//因为前面已经确定mid也不是target,所以right可以跳过mid
                else
                    left = mid+1;
            }
            else if(nums[mid]<nums[left])//中间元素<左边元素，[mid,right]是一个递增区间
            {
                if(target>=nums[mid]&&target<=nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
            else//nums[mid]==nums[left]
                left++;
            mid = left+(right-left)/2;
        }
        return false;
    }
};
