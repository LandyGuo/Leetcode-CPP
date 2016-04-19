/*
77. Combinations 
Difficulty: Medium
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
/*
思路：dfs回溯
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        if(k<=0)
            return res;
        vector<int> path;
        dfs(1,n,k,path,res);
        return res;
    }
    
    
    void dfs(int start,int end,int depth,vector<int>&path,vector<vector<int>>&res)
    {
        if(depth==0)
        {
            res.push_back(path);
            return;
        }
        else
        {
            for(int i=start;i<=end;i++)
            {
                path.push_back(i);
                dfs(i+1,end,depth-1,path,res);
                path.pop_back();
            }
        }
        
        
    }
};
