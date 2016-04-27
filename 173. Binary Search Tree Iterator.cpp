/*
173. Binary Search Tree Iterator  
Difficulty: Medium
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //2nd pass
 /*
 思路：维持一个全局栈，每当弹出一个节点，如果这个节点有右孩子，就把右孩子的所有左孩子全部压入；
 主要考察二叉树的非递归中序遍历
 */
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode *root) {
        TreeNode* p = root;
        while(p)
        {
            s.push(p);
            p = p->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.empty()?false:true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = s.top();
        s.pop();
        if(cur->right)
        {
            TreeNode* p = cur->right;
            while(p)
            {
                s.push(p);
                p = p->left;
            }
        }
        return cur->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
