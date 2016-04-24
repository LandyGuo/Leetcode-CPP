/*
124. Binary Tree Maximum Path Sum   My Submissions QuestionEditorial Solution
Total Accepted: 63514 Total Submissions: 272619 Difficulty: Hard
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
 /*
 思路：
 以当前结点为根可以选择2个分支,更新最终的结果
如果root需要返回值，则root返回给上层用，此时root作为上层的一个分支，只能选择一个分支返回
(选2个分支就不是沿着parent-child的路线)，如果root->val+max(left,right)<0,则连root也舍弃，全部都不要

               1
              / \
            -2   3
            /\
           4  5
以-2作为根节点时，沿着parent-child的路线：值为-2+4+5（更新值）
以1作为根节点时，沿着（5->-2，是-2节点的返回值）->1->3 的路线取得最大值，注意：4不能加上，否则就不是parent-child的路线
            
 */
class Solution {

public:
    int maxPathSum(TreeNode* root) {
        int max_value = INT_MIN;
        dfs(root,max_value);
        return max_value;
    }
    
    int dfs(TreeNode* root,int & max_value)
    {
        if(root==NULL)
            return 0;
        int leftSum = max(0,dfs(root->left,max_value));
        int rightSum = max(0,dfs(root->right,max_value));
        int cur_node_sum = root->val+leftSum+rightSum;
        max_value = max(max_value,cur_node_sum);//以当前结点为根可以选择2个分支,更新最终的结果
        //如果root需要返回值，则root返回给上层用，此时root作为上层的一个分支，只能选择一个分支返回(选2个分支就不是沿着parent-child的路线)，如果root->val+max(left,right)<0,则连root也舍弃，全部都不要
        int choose_root_and_child_max = max(max(leftSum,rightSum)+root->val,0);
        return choose_root_and_child_max;//由下而上只能返回一个分支，因为返回值是给根节点用的
    }
};
