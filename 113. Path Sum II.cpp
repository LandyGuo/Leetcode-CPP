/*
113. Path Sum II  
Difficulty: Medium
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //2nd pass
 /*
 思路：dfs到叶子节点，判断是否为0，为0就加上path
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        if(root==NULL)  
            return res;
        vector<int> path;
        path.push_back(root->val);
        dfs(root,sum-root->val,path,res);
        return res;
    }
    
    void dfs(TreeNode* root, int target, vector<int>&path,vector<vector<int>>&res)
    {
        if(root->left==NULL && root->right==NULL)//叶子节点
        {
            if(target==0)
                res.push_back(path);
            return;
        }
        vector<TreeNode*>choices;
        if(root->left!=NULL) choices.push_back(root->left);
        if(root->right!=NULL) choices.push_back(root->right);
        for(TreeNode* cur:choices)
        {
            path.push_back(cur->val);
            dfs(cur,target-cur->val,path,res);
            path.pop_back();
        }
        
    }
};
