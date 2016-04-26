/*
230. Kth Smallest Element in a BST  
Difficulty: Medium
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
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
 //思路：用非递归的二叉树的中序遍历，中序遍历过程中是一个递增的数列，用k来计数
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode*p = root;
        while(p)//压入所有的左孩子
        {
            s.push(p);
            p = p->left;
        }
        int res=-1;
        while(!s.empty())//中序遍历
        {
            TreeNode* cur =  s.top();
            s.pop();
            k--;
            if(k==0)
            {
                res = cur->val;
                break;
            }
            if(cur->right)//如果当前出栈节点有右孩子，把右孩子的所有左孩子压入栈
            {
                TreeNode * p= cur->right;
                while(p)
                {
                    s.push(p);
                    p = p->left;
                }
            }
        }
        return res;
    }
};
