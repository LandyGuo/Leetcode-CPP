/*
215. Kth Largest Element in an Array   
Difficulty: Medium
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
/*2nd pass
思路：基本算法
注意在c++中随机一个[0,N)的数，rand()%N;这里pivot的选择一定要随机，否则如果遇到完全有序的数组会过不了大的测试集合
*/
#define random(x) (rand()%x)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int>lt_pivot,gt_pivot;
        int pivot = nums[random(nums.size())];
        for(int num:nums)
        {
            if(num>pivot) gt_pivot.push_back(num);
            else if(num<pivot) lt_pivot.push_back(num);
        }
        if(k<=gt_pivot.size())
            return findKthLargest(gt_pivot,k);
        else if(k>nums.size()-lt_pivot.size())
            return findKthLargest(lt_pivot,k-(nums.size()-lt_pivot.size()));
        else
            return pivot;
    }
};
