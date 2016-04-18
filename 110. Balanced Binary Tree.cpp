/*
110. Balanced Binary Tree  
Difficulty: Easy
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
 /*2nd pass
 思路：一个二叉树平衡当且仅当 以当前结点为根的二叉树平衡，左子树平衡且右子树平衡
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return abs(getHeight(root->left)-getHeight(root->right))<=1&&isBalanced(root->left)&&isBalanced(root->right);
    }
    
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1+max(getHeight(root->left),getHeight(root->right));
    }
};
