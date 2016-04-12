/*
47. Permutations II 
Difficulty: Medium
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
/**
 * 思路：不断产生下一个组合，知道与第一个相同为止
 * */

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>>res;
		if (nums.size() == 0)
			return res;
		res.push_back(vector<int>(nums.begin(), nums.end()));
		if (nums.size() == 1)
			return res;
		vector<int> start = nums;//yes:deepcopy here!
		changeNextPermutation(nums);
		while (start != nums)
		{
			res.push_back(vector<int>(nums.begin(), nums.end()));
			changeNextPermutation(nums);
		}
		return res;
	}

	void changeNextPermutation(vector<int>&nums)//第31题：nextPermutation问题
	{
		int p1, p2;
		p1 = nums.size() - 2, p2 = p1 + 1;
		while (p1 >= 0 && nums[p1] >= nums[p2])
		{
			p1--; p2--;
		}
		if (p1 == -1)
		{
			reverse(nums.begin(),nums.end());
			return; 
		}
		int k = nums.size() - 1;
		while (nums[k] <= nums[p1])k--;
		swap(nums[k], nums[p1]);
		reverse(nums.begin() + p1 + 1, nums.end());
	}
};
