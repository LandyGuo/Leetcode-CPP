/*
257. Binary Tree Paths   
Difficulty: Easy
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
 //思路：
 //回溯法进行dfs,每当到达叶子节点，就把Path中的节点值都join起来
 //
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        if(root==NULL)
            return res;
        vector<int>path;
        path.push_back(root->val);
        dfs(root,path,res);
        return res;
    }
    
    void dfs(TreeNode* root,vector<int>&path,vector<string>&res)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)//到达叶子节点
        {
            string tmp;
            for(int i=0;i<path.size();i++)
            {
                char buf[32];
                sprintf(buf,"%d",path[i]);
                string add = string(buf);
                if(i!=path.size()-1)
                    add+="->";
                tmp+=add;
            }
            res.push_back(tmp);
        }
        vector<TreeNode*> curChoices;
        if(root->left!=NULL)
            curChoices.push_back(root->left);
        if(root->right!=NULL)
            curChoices.push_back(root->right);
        for(TreeNode* cur:curChoices)
        {
            path.push_back(cur->val);
            dfs(cur,path,res);
            path.erase(path.end()-1);
        }
    }
};
