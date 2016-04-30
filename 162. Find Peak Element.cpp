/*
162. Find Peak Element  
Difficulty: Medium
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
*/
//2nd pass
/*
1)证明：如果num[-1] = num[n] = -∞.那么峰值一定存在。
因为nums[-1] =  -∞.因此 nums[0]>nums[-1],如果峰值不存在，那么nums[0]<nums[1],同理 nums[1]<nums[2] 因为如果nums[2]>nums[1],nums[2]就是峰值
因此，nums[-1]<nums[0]<nums[1]<nums[2]<..<nums[length-1]>nums[length](nums[length] =  -∞),因此nums[length-1]一定为峰值
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int l = 0,r = nums.size()-1,mid = l+(r-l)/2;
        while(l<=r)
        {
            int mid_l_val = mid==0?INT_MIN:nums[mid-1];
            int mid_r_val = mid==nums.size()-1?INT_MIN:nums[mid+1];
            if(nums[mid]>=mid_l_val&&nums[mid]>=mid_r_val)//峰值,因为题目中没有重复的数，因此遇到重复的数只可能发生在边界(如果数组第一个或最后一个为INT_MIN)
                return mid;
            else if(nums[mid]<mid_l_val)//nums[mid]<nums[mid-1],让r = mid-1,尽可能包含峰值
                r = mid-1;
            else if(nums[mid]<mid_r_val)//nums[mid]<nums[mid+1],让l = mid+1,尽可能包含峰值
                l = mid+1;
            mid = l+(r-l)/2;
        }
        return -1;
    }
};
