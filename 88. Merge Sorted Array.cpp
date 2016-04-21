/*
88. Merge Sorted Array  
Difficulty: Easy
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/
/*2nd pass
        思路：
        归并排序中合并的步骤，不过由于是要合并到A中，也就是不申请额外空间，因此，为了减少移动A重元素的次数，考虑从后往前逐步合并：从后往前遍历A和B数组，每次把大的数字从A中m+n位置逐步往前放。
        时间复杂度：O(m+n)
        空间复杂度：O(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=m-1,p2=n-1;
        int curpos = m+n-1;
        while(p1>=0&&p2>=0)
        {
            if(nums1[p1]>=nums2[p2])
                nums1[curpos--] = nums1[p1--];
            else 
                nums1[curpos--] = nums2[p2--];
        }
        while(p1>=0)
            nums1[curpos--] = nums1[p1--];
        while(p2>=0)
            nums1[curpos--] = nums2[p2--];
    }
};
