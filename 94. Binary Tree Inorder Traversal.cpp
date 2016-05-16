/*
94. Binary Tree Inorder Traversal  
Difficulty: Medium
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

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
 /*思路：
 二叉树的中序遍历：先疯狂的压入左孩子，然后弹出节点时检查是否有右孩子，如果有右孩子，再疯狂的压入右孩子的左孩子，直到栈为空
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        if(root==NULL) return ret;
        stack<TreeNode*>s;
        TreeNode *p = root;
        while(p)
        {
            s.push(p);
            p = p->left;
        }
        while(!s.empty())
        {
            TreeNode* cur = s.top();
            s.pop();
            ret.push_back(cur->val);
            if(cur->right)
            {
                TreeNode* p = cur->right;
                while(p)
                {
                    s.push(p);
                    p = p->left;
                }
            }
        }
        return ret;
    }
};
