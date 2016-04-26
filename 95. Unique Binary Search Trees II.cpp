/*
95. Unique Binary Search Trees II   
Difficulty: Medium
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
 //思路：
 //遍历所有的可行方案，将当前节点左边的所有组合依次作为左子树，右边的所有可能组合依次作为右子树，递归进行构建
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0)
            return vector<TreeNode*>();
        return genTrees(1,n);
    }
    
    vector<TreeNode*> genTrees(int start,int end)
    {
        vector<TreeNode*>res;
        if(start>end)//对于没有子树的处理
        {
            res.push_back(NULL);
            return res;
        }
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*>leftChildren = genTrees(start,i-1);//构建时比当前节点小的都在左边
            vector<TreeNode*>rightChildren = genTrees(i+1,end);//比当前节点大的都在右边
            for(TreeNode* c1:leftChildren)
            {
                for(TreeNode* c2:rightChildren)
                {
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = c1;
                    tmp->right = c2;
                    res.push_back(tmp);
                }
            }
        }
        return res;
        
    }
};
