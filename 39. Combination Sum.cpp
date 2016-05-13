/*
39. Combination Sum  
Difficulty: Medium
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/
//2nd pass
/*
思路：
1.将candidates从小到大排序，这样就将所有序列中的数字依次递增的条件约束改为下标依次递增（如果
同一个数字可以重复使用，那么就从小到大递增就可以包含初始下标，否则不包含（这是唯一的区别））
2.关于去重的问题：
由于所有子集不能重复，因此同一层不能有相同的孩子，否则就会导致重复(每一层都要做去重判断)
*/
class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>>ret;
		if (candidates.empty() || target <= 0) return ret;
		sort(candidates.begin(), candidates.end());
		vector<int> path;
        dfs(candidates,0,target,path,ret);
		return ret;
	}

	void dfs(vector<int>& candidates,int cur_index,int cur_target, vector<int>&path, vector<vector<int>>&res)
	{
		if (cur_target == 0)
			res.push_back(path);
		else if (cur_target<0)
			return;
		else
		{
			for (int i=cur_index;i<candidates.size();i++)
			{
				if (candidates[i]>cur_target)
					break;
				if (i != cur_index && candidates[i] == candidates[i - 1]) continue;
				path.push_back(candidates[i]);
				dfs(candidates,i, cur_target - candidates[i], path, res);
				path.pop_back();
			}
		}
	}
};
