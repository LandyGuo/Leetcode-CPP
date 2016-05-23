/*
144. Binary Tree Preorder Traversal
Difficulty: Medium
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
 思路：二叉树的先序遍历，中左右；需要注意的是入栈时为了先访问左子树，需要先将右子树入栈
 
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ret;
        if(root==NULL) return ret;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();
            ret.push_back(cur->val);
            if(cur->right)
                s.push(cur->right);
            if(cur->left)
                s.push(cur->left);
        }
        return ret;
        
    }
};
