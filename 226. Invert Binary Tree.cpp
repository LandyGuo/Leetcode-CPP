/*
226. Invert Binary Tree  
Difficulty: Easy
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
 //思路：交换当前节点的左右子树，递归进行
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        else
        {
            swap(root->left,root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};
