/*
101. Symmetric Tree  
Difficulty: Easy
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
//两个节点对称，要么都为空，要么都不为空且值相等，
//递归check 两个节点，以及处于两个节点孩子中处于对称位置的孩子节点
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return check(root->left,root->right);
    }
    
    bool check(TreeNode* r1,TreeNode* r2)
    {
        if(r1==NULL&&r2==NULL)
            return true;
        else if(r1&&r2)
            return (r1->val==r2->val)&&check(r1->left,r2->right)&&check(r1->right,r2->left);
        else
            return false;
    }
};
