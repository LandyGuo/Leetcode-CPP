/*
80. Remove Duplicates from Sorted Array II 
Difficulty: Medium
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/
/**
 * pass2
 *思路：
 * 排好序的数组，与第26题类似，不同在于允许重复2次，因此前两个一定是valid的，从第3个开始
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)
            return nums.size();//前2个一定是valid的
        int p1,p2;
        p1=p2=2;//从第3个元素开始判断
        while(p2<nums.size())
        {
            if(nums[p2]!=nums[p1-2])//p2指向当前处理的元素，与在它之前2个元素相比，如果不相同,则可以放在当前p1指向的位置
                nums[p1++] = nums[p2++];
            else
                p2++;
        }
        return p1;//p1之前都是valid
    }
};
