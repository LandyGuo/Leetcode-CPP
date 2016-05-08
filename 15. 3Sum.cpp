/*
15. 3Sum   My Submissions QuestionEditorial Solution
Total Accepted: 116362 Total Submissions: 617333 Difficulty: Medium
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
//2nd pass
/*
思路：将3-sum转换为2-sum问题：先排序
1)注意对target去重,为什么？显然前面的target已经包含了后面相同target的所有可能!!
2)对2-sum内部进行去重，相等时对j,k同时进行去重
当相等的时候,[1,-1,0,-1,0]的情况，避免返回[[1,-1,0],[1,-1,0]]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ret;
        if(nums.size()<3) return ret;//少于3个数字直接返回空
        sort(nums.begin(),nums.end());
        int last_target = INT_MAX;
        for(int i=0;i<nums.size()-2;i++)
        {
            int cur_target = 0-nums[i];
            if(cur_target==last_target)//对cur_target进行去重
                continue;
            last_target = cur_target;
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[j]+nums[k]>cur_target)
                    k--;
                else if(nums[j]+nums[k]<cur_target)
                    j++;
                else
                {
                    vector<int> tmp = {nums[i],nums[j],nums[k]};
                    ret.push_back(tmp);
                    j++,k--;
                    while(j<nums.size()&&nums[j]==nums[j-1])j++;//对相同的nums[j]和nums[k]去重
                    while(k>0&&nums[k]==nums[k+1])k--;
                }
            }
        }
        return ret;
    }
};
