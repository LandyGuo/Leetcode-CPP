/*
143. Reorder List  
Difficulty: Medium
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /*2nd pass
  * 思路：
  1.链表拆分(注意：拆分之前的链表尾部置空)-----基本操作
  2.将第二个链表倒置--------基本操作
  3.将第二个链表插入第一个链表-------基本操作
  * 
  */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next)
            return;
        ListNode*p1 = head,*p2 = split(p1);
        ListNode* reverse_p2 = reverse(p2);
        head = merge(p1,reverse_p2);
    }
    
    ListNode* merge(ListNode*p1,ListNode*p2)
    {
        ListNode* new_head = new ListNode(-1);
        ListNode*p = new_head;
        bool flag = true;
        while(p1&&p2)
        {
            if(flag)
            {
                ListNode* p1_next = p1->next;
                p1->next = NULL;
                p->next = p1;
                p = p->next;
                p1=p1_next;
                flag = false;
            }
            else
            {
                ListNode* p2_next = p2->next;
                p2->next = NULL;
                p->next = p2;
                p = p->next;
                p2 = p2_next;
                flag= true;
            }
        }
        if(p1)
            p->next = p1;
        else
            p->next = p2;
        return new_head->next;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode *p=head->next,*last=head;
        head->next = NULL;
        while(p)
        {
            ListNode* p_next = p->next;
            new_head->next = p;
            p->next = last;
            last = p;
            p = p_next;
        }
        return new_head->next;
    }
    
    ListNode* split(ListNode* head)
    {
        if(!head)
            return NULL;
        ListNode*p1=head,*p2=p1,*pre_p1=NULL;
        while(p2)
        {
            pre_p1 = p1;
            p1 = p1->next;
            if(p1)
                p2 = p2->next?p2->next->next:NULL;
        }
        pre_p1->next = NULL;
        return p1;
    }
};
