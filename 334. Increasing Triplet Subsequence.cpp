/*
334. Increasing Triplet Subsequence  
Difficulty: Medium
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/
//2nd pass
/*
        思路：用(a,b)来表示两个距离最小的递增序列，显然来一个数x,x<=a则更新a;x在(a,b] 考虑更新b,x>b，则返回True
        初始化时为(None,None)
        来一个数，更新a
        再来一个数，如果比a小，则不能构成递增序列，仍然更新a;如果比a大，则可以构成递增序列，更新b
        如果(a,b)都没构建完成（说明没找到两个的递增序列），此时肯定也不存在3个的递增序列
        构建完成后，按以上规则进行更新，如果出现比b大的则说明一定存在递增的三元组
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a1 = INT_MIN,a2 = INT_MIN;
        for(int num:nums)
        {
            if(a1==INT_MIN||num<=a1)
            {
                a1 = num;
                continue;
            }
            if(a2==INT_MIN||(num>a1&&num<=a2))
            {
                a2 = num;
                continue;
            }
            if(num>a2)
                return true;
        }
        return false;
    }
};
