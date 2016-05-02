/*
203. Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //2nd pass
 /*
 思路：因为第一个节点也有可能是要删除的节点，因此加头结点*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* p =head,*pre_p = new_head;
        while(p)
        {
            if(p->val==val)
            {
                pre_p->next = p->next;
                p = pre_p->next;
            }
            else
            {
                pre_p = p;
                p = p->next;   
            }
        }
        return new_head->next;
        
    }
};
