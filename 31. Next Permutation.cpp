/*
31. Next Permutation
Difficulty: Medium
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
Subscribe to see which companies asked this question
*/
/**
 *pass2: 
 * 经典问题：求组合数的下一个组合
 * 1.从后往前找到第一个顺序递增的2个数，p1,p2(p1指向前面一个数)
 * 2.根据p1值，判断是否已经完全逆序；完全逆序则再次全部逆序即可
 * 3.若不是完全逆序，则固定p1,k从后往前，找第一个比p1大的数(一定找得到，因为第一步中最起码p2肯定能满足)
 * 4.交换k和p1,然后将p1之后全部逆序
 s*/


class Solution {
public:
	void nextPermutation(vector<int>& nums) {
        if(nums.size()<=2)//少于2个数直接完全逆序即可
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int p1,p2;
        p1 = nums.size()-2,p2=p1+1;
        while(p1>=0 && nums[p1]>=nums[p2])//从后往前找到第一个顺序递增的2个数，p1,p2(p1指向前面一个数)；
        //第一次不能AC:while(p1>=0 && nums[p1++]>=nums[p2++]),这样不论是否满足，只要比较了,就会执行p1++,p2++
        {
            p1--;
            p2--;
        }
        if(p1==-1)//p1==-1表示已经完全逆序
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int k = nums.size()-1;
        while(nums[k]<=nums[p1])k--;//从后往前找k:第一个比p1大的数(一定找得到，因为第一步中最起码p2肯定能满足)
        swap(nums[p1],nums[k]);//交换k和p1,然后将p1之后全部逆序
        reverse(nums.begin()+p1+1,nums.end());
	}
};
