/*
18. 4Sum  
Difficulty: Medium
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
//2nd pass
/*
思路：
直接调用3-sum;注意去重
相同target去重，求和判断相等的时候去重
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size()<4) return ret;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++)
        {
            int cur = target-nums[i];
            if(i!=0&&nums[i]==nums[i-1]) continue;
            threeSum(nums.begin()+i+1,nums.end(),cur,nums[i],ret);
        }
        return ret;
    }
    
    
    void threeSum(vector<int>::iterator begin,vector<int>::iterator end, int target,int first,vector<vector<int>>&ret)
    {
        if(end-begin<3) return ;
        for(auto p = begin;p!=end-2;p++)
        {
            int cur = target -*p;
            if(p!=begin&&(*p)==*(p-1)) continue;
            vector<int>::iterator i=p+1,j=end-1;//i = p+1 ,写程序时保证头脑清醒
            while(j>i)
            {
                if((*i+*j)==cur)
                {
                    ret.push_back({first,*p,*i,*j});
                    i++,j--;
                    while(i!=end&&*i==*(i-1))i++;
                    while(j>i&&*j==*(j+1))j--;
                }
                else if((*i+*j)>cur)
                    j--;
                else 
                    i++;
            }
        }
    }
};
