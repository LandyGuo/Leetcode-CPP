/*
199. Binary Tree Right Side View 
Difficulty: Medium
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
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
 思路：二叉树层序遍历，每次将每一层最后一个节点的值压入即可
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ret;
        if(root==NULL) return ret;
        queue<TreeNode*>q;
        q.push(root);
        int cnt = q.size();
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            cnt--;
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
            if(cnt==0)
            {
                cnt = q.size();
                ret.push_back(cur->val);
            }
        }
        return ret;
    }
};
