/*
169. Majority Element  
Difficulty: Easy
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

/*2nd pass
思路：voting :两两不同的数抵消，最后剩下的数就一定是主元素
这种算法对于存在主元素的数组是有效的，如：

A A A C C B B C C C B C C

它肯定能返回主元素C。但是，如果不存在主元素，那么得到的结果就跟遍历顺序有关了。如:

A A A C C C B

如果是从左到右，那么结果是B，如果是从右到左，那么结果是A。*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0],support = 1;
        for(int i=1;i<nums.size();i++)
        {
            if(support==0)
            {
                major = nums[i];
                support = 1;
            }
            else if(nums[i]==major)
                support+=1;
            else
                support-=1;
        }
        return major;
    }
};
