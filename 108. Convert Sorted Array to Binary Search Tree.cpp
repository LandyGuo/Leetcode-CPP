/*
108. Convert Sorted Array to Binary Search Tree  
Difficulty: Medium
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
 每次找中点，递归建树
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums.begin(),nums.end());
    }
    
    TreeNode* build(vector<int>::iterator p1,vector<int>::iterator p2)
    {
        if(p1>=p2)
            return NULL;
        int length = p2-p1;
        auto p = p1;
        for(int i=0;i<length/2;i++)//找中点
            p++;
        TreeNode * root = new TreeNode(*p);
        root->left = build(p1,p);//递归建树
        root->right = build(p+1,p2);
        return root;
    }
};
