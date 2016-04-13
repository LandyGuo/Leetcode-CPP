/*
78. Subsets 
Difficulty: Medium
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
/*2nd pass
    思路：
    1 2 3 
    先初始化为[]
    [] res=[]
    然后从后往前处理:
    3  res =[],([3])
    2  res = [],[3],([2],[2,3])
    1  res = [],[3],[2],[2,3],([1],[1,3],[1,2],[1,2,3])
    后面的括号为新产生的，在前面的基础之上全部在首部添加新来的数
    这种方法比递归产生更高效，而且更容易实现
*/
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		sort(nums.begin(), nums.end());//increasing training
		vector<vector<int>> res;
		res.push_back(vector<int>());
		for(int i=nums.size()-1;i>=0;i--)
		{
		    vector<vector<int>> res_cp =res;
		    int cur_num = nums[i];
		    for(vector<int> subset:res_cp)
		    {
		        subset.insert(subset.begin(),nums[i]);
		        res.push_back(subset);
		    }
		}
		return res;
	}

};
