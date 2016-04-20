/*
216. Combination Sum III  
Difficulty: Medium
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
*/
/*2nd pass
dfs:到达第k层时剪枝，判断结果是否为target,为target加入res
*/

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int>tmp;
		vector<vector<int>>res;
		dfs(0, k, n, tmp, res);
		return res;
	}


	void dfs(int lastnum, int depth, int target, vector<int>&path, vector<vector<int>>&res)
	{
		if (depth == 0)
		{
			if (target == 0)
				res.push_back(path);
			return;
		}
		else
		{
			for (int i = lastnum + 1; i <= 9; i++)
			{
				if (i > target)
					break;
				path.push_back(i);
				dfs(i, depth - 1, target - i, path, res);
				path.pop_back();
			}

		}

	}
};
