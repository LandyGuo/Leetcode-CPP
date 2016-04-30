/*
112. Path Sum 
Difficulty: Easy
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
 //dfs到叶子节点判断
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        return dfs(root,sum-root->val);
        
    }
    
    bool dfs(TreeNode* root,int target)
    {
        if(target==0&&root->left==NULL&&root->right==NULL)//dfs到叶子节点进行判断 
            return true;
        vector<TreeNode*> choices;
        if(root->left)
            choices.push_back(root->left);
        if(root->right)
            choices.push_back(root->right);
        for(TreeNode* cur:choices)
        {
            if(dfs(cur,target-cur->val))//有一条路径满足就返回
                return true;
        }
        return false;
    }
};
