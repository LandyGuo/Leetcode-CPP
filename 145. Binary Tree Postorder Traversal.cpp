/*
145. Binary Tree Postorder Traversal
Difficulty: Hard
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
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
后序遍历：左右中
思路：先压入根节点，
取栈顶结点，判断当前结点是否能弹出(其右孩子已经弹出->右孩子为空，左孩子是上次弹出的节点；右孩子不为空，右孩子是上次弹出的节点，左右孩子都为空)
满足这3种情况中的一种即可弹出~
 如果不满足弹出条件，才需要看能不能压入其左右孩子*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ret;
        if(root==NULL) return ret;
        stack<TreeNode*>s;
        s.push(root);
        TreeNode* lastNode =NULL;
        while(!s.empty())
        {
            TreeNode* cur = s.top();
            if((cur->left==NULL&&cur->right==NULL)||
                (cur->right==NULL&&cur->left==lastNode)||(cur->right!=NULL&&cur->right==lastNode))
            {
                s.pop();
                ret.push_back(cur->val);
                lastNode = cur;
            }
            else if(cur->left||cur->right)
            {
                if(cur->right) s.push(cur->right);
                if(cur->left) s.push(cur->left);
            }
            
        }
        return ret;
    }
};
