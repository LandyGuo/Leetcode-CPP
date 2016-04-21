/*
222. Count Complete Tree Nodes  
Difficulty: Medium
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, 
and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
 判断子树是不是满二叉树，对于完全二叉树而言，如果左子树高度等于右子树高度，那么一定是满二叉树;
 满二叉树的节点数 = 2^h-1(h为树高)
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int leftLevel = getHeight(root,true);
        int rightLevel = getHeight(root,false);
        if(leftLevel==rightLevel)
            return pow(2,leftLevel)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
        
    }
    
    
    
    int getHeight(TreeNode* root,bool isLeft = true)
    {
        if(!root)
            return 0;
        if(isLeft) return getHeight(root->left,true)+1;
        else return getHeight(root->right,false)+1;//注意这里：求右边的树高时，要把false参数传进去！！
    }
};
