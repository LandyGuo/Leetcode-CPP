/*
337. House Robber III 
Difficulty: Medium
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
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
 思路：
动规:opt[node][0]---不抢node节点的最大收益 opt[node][1]---可抢可不抢node节点时的最大收益
Rob(node,NocanRob) = Rob(node.left,canRob)+Rob(node.right,canRob)
Rob(node,canRob) = max(node.val+Rob(node.left,NocanRob)+Rob(node.right,NocanRob),Rob(node,NocanRob)) 
 ---------递归会导致重复计算
 用opt[node][0] = Rob(node,NocanRob)(不能抢最大收益) ,opt[node][1] = Rob(node,canRob) (可强可不抢最大收益)
 */
class Solution {
public:
	int rob(TreeNode* root) {
		map<TreeNode*, int[2]>opt;
		return Rob(root,true,opt);

	}

	int Rob(TreeNode* root, bool canRob, map<TreeNode*, int[2]>&opt)
	{
	    if(!root)
	        return 0;
		if (opt.find(root)==opt.end())
		{
			int no_rob_profit, rob_or_no_rob_profit;
			//不能抢
			no_rob_profit = Rob(root->left, true, opt) + Rob(root->right, true, opt);
			//可以抢，抢或不抢
			rob_or_no_rob_profit = max(root->val + Rob(root->left, false, opt) + Rob(root->right, false, opt),
				no_rob_profit);
			opt[root][0] = no_rob_profit;
			opt[root][1] = rob_or_no_rob_profit;
		}
		return canRob ? opt[root][1] : opt[root][0];
	}
};
