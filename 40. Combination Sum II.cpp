/*
40. Combination Sum II 
Difficulty: Medium
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/
/*2nd-pass
思路:与39题完全相同，每一层都不能有相同的节点
*/
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>>ret;
		if (candidates.empty() || target <= 0) return ret;
		sort(candidates.begin(), candidates.end());
		vector<int> path;
        dfs(candidates,-1,target,path,ret);
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
			for (int i=cur_index+1;i<candidates.size();i++)
			{
				if (candidates[i]>cur_target)
					break;
				if (i != cur_index+1 && candidates[i] == candidates[i - 1]) continue;
				path.push_back(candidates[i]);
				dfs(candidates,i, cur_target - candidates[i], path, res);
				path.pop_back();
			}
		}
	}
};
