/*
103. Binary Tree Zigzag Level Order Traversal  
Difficulty: Medium
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root)
            return res;
        deque<TreeNode*> que;
        que.push_back(root);
        int cnt = que.size();//当前层节点计数，为0表明当前层最后一个节点已经弹出
        vector<int> tmp;//暂存当前层的节点
        bool reverse_flag=false;//当前层是否翻转标志位
        while(!que.empty())
        {
            TreeNode* curNode = que.front();
            que.pop_front();
            tmp.push_back(curNode->val);
            cnt--;
            if(curNode->left)
                que.push_back(curNode->left);
            if(curNode->right)
                que.push_back(curNode->right);
            if(cnt==0)
            {
                if(reverse_flag)
                    reverse(tmp.begin(),tmp.end());
                res.push_back(tmp);
                tmp.clear();
                reverse_flag=!reverse_flag;
                cnt = que.size();
            }
        }
        return res;
    }
};
