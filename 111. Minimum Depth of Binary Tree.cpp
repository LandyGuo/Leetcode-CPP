/*
111. Minimum Depth of Binary Tree  
Difficulty: Easy
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
 注意：是到叶子节点的距离，
     1
    /
   2
 距离为2，不能算1的右孩子空节点为叶子节点。
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        else if(root->left&&root->right)
            return min(minDepth(root->left),minDepth(root->right))+1;
        else if(root->left&&!root->right)//因为空节点不算叶子节点，所以人工选择走向非空的节点去计算路径
            return minDepth(root->left)+1;
        else if(!root->left&&root->right)
            return minDepth(root->right)+1;
        else //叶子节点，返回高度为1
            return 1;
    }
};
