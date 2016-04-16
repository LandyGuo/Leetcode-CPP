/*
220. Contains Duplicate III   
Difficulty: Medium
Given an array of integers, find out whether there are two distinct indices i and j in the array 
such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/
/*2nd pass
思路：维持一个元素个数为k的集合，每次来一个数与其之前的k个数进行比较(这样下标问题就肯定满足)，剩下的是值问题；
为了避免每次来一个元素就遍历一遍之前的k个数(这样复杂度是O(nk)),需要用用二叉树的查找算法，查找满足：|nums[i]-nums[j]|<=t
的nums[i]
nums[j]-t    <=nums[i]<=nums[j]+t
由于lower_bound查找大于等于nums[j]-t的数，如果没找到，肯定没有满足的，如果找到，那么检验找到的数能否满足<=nums[j]+t,满足就存在
有序的set(红黑树-平衡二叉树)构成一个二叉查找树，
*/
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> iset;
        for(int i=0; i<nums.size();i++)
        {
            if(iset.size()==k+1)//维持set中有k个元素作为查找集
                iset.erase(nums[i-k-1]);
            long long curNum = nums[i];//特别注意这里：如果是int,curNum+t(t可能很大)可能会溢出，溢出后会变成负数，与*p(longlong)会转为longlong 仍然为负数，这里会出问题
            set<long long>::iterator p = iset.lower_bound(curNum-t);
            if(p!=iset.end()&&(*p)<=curNum+t)
                return true;
            iset.insert(nums[i]);
        }
        return false;
    }
};
