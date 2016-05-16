/*
116. Populating Next Right Pointers in Each Node  
Difficulty: Medium
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
  //2nd pass
 /*
 思路：
        1              1)将当前层的所有节点当作一个链表进行遍历；遍历过程中将每个节点的左孩子指向右孩子;并将上一个节点的右孩子指向当前
       /  \
      2    3            节点的左孩子，
     / \  / \
    4  5  6  7          2)从上层到下层按1->2->4同样按照访问链表的方式进行层序向下
 
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL) return;
        TreeLinkNode*p= root;
        while(p&&p->left&&p->right)
        {
            TreeLinkNode* next = p->left;//下一层节点
            TreeLinkNode* pre = NULL;
            while(p)
            {
                p->left->next = p->right;
                if(pre)
                    pre->right->next = p->left;
                pre =p,p=p->next;
            }
            p = next;
        }
    }
};
