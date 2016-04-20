/*
90. Subsets II   
Difficulty: Medium
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
/*2nd pass
思路：先排序 1,3,4,4,5,
先生成[],[5]
从4开始往前生成:
4(与5不同,直接全部复制[],[5]，然后在前面插入4): [],[5],[4],[4,5]
4(与前一个4相同,复制增加的部分[4],[4,5],然后在前面插入4):[],[5],[4],[4,5],[4,4],[4,4,5]
3(与前一个4不同，全部复制，前面插入3):[],[5],[4],[4,5],[4,4],[4,4,5],   [3],[3,5],[3,4],[3,4,5],[3,4,4],[3,4,4,5]
1 同3
因此，只有与前面一个数不同才会全部复制(修改复制长度)，否则只用复制新增的部分(复制长度不变)
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res(1,vector<int>());
        if(nums.empty())
            return res;
        res.push_back(vector<int>(1,nums[nums.size()-1]));
        int p = nums.size()-2;
        int last_add_size = 1;
        while(p>=0)
        {
            if(nums[p]!=nums[p+1])
                last_add_size = res.size();//不想等，更新复制长度为全部；相等的话，不修改复制长度
                //，即前一个与之相等的数复制多少，它也复制多少
            int copy_size = res.size();
            for(int i=copy_size-last_add_size;i<copy_size;i++)
            {
                    vector<int> tmp = res[i];
                    tmp.insert(tmp.begin(),nums[p]);
                    res.push_back(tmp);
            }
            p--;
        }
        return res;
    }
};
