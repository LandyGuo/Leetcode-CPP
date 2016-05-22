/*
106. Construct Binary Tree from Inorder and Postorder Traversal 
Difficulty: Medium
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
 //2nd pass
 /*
 中序遍历:左中右
 后序遍历:左右中
 在后序遍历中的最后一个节点就是根节点，在中序遍历中找根节点的位置，根节点左边的都是左孩子，右边的都是右孩子，递归查找
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        assert(inorder.size()==postorder.size());
        return build(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
    }
    
    TreeNode* build(vector<int>::iterator i1,vector<int>::iterator i2,vector<int>::iterator p1,vector<int>::iterator p2)
    {
        if(p1==p2) return NULL;
        TreeNode*  root = new TreeNode(*(p2-1));
        auto pos = find(i1,i2,*(p2-1));
        int leftSize = pos-i1;
        root->left = build(i1,pos,p1,p1+leftSize);
        root->right = build(pos+1,i2,p1+leftSize,p2-1);
        return root;
    }
};
