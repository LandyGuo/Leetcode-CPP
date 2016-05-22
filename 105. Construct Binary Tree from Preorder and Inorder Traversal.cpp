/*
105. Construct Binary Tree from Preorder and Inorder Traversal 
Difficulty: Medium
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
 先序遍历:中左右
 中序遍历:左中右
 在先序遍历中的第一个节点就是根节点，在中序遍历中找根节点的位置，根节点左边的都是左孩子，右边的都是右孩子，递归查找
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        assert(preorder.size()==inorder.size());
        return build(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
    
    TreeNode* build(vector<int>::iterator p1,vector<int>::iterator p2,vector<int>::iterator i1,vector<int>::iterator i2)
    {
        if(p1==p2) return NULL;
        TreeNode*  root = new TreeNode(*p1);
        auto pos = find(i1,i2,*p1);
        int leftSize = pos-i1;
        root->left = build(p1+1,p1+leftSize+1,i1,pos);
        root->right = build(p1+leftSize+1,p2,pos+1,i2);
        return root;
    }
};
