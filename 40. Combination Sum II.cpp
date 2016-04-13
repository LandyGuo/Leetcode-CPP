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
思路：
多个数的组合和，和固定的2-sum，3-sum问题有本质区别，用dfs遍历所有可能的情形
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>res;
        vector<int>path;
        dfs(candidates.begin(),candidates.end(),target,path,res);
        return res;
    }
    
    
    void dfs(vector<int>::iterator p1,vector<int>::iterator p2,int target,vector<int>&path,vector<vector<int>>&res)
    {
        if(target==0)
        {
            if(find(res.begin(),res.end(),path)==res.end())
            {
                res.push_back(path);
            }
            return;
        }
        for(auto p= p1;p!=p2;p++)
        {
            if(*p>target)
                continue;
            path.push_back(*p);
            dfs(p+1,p2,target-*p,path,res);
            path.pop_back();
        }
        
    }
};
