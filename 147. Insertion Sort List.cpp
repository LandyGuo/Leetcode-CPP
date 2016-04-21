/*
147. Insertion Sort List  
Difficulty: Medium
Sort a linked list using insertion sort.
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
 思路：因为可能在第一个节点之前插入，需要增加头节点
 另外插入位置的确定用前驱指针
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* new_head = new ListNode(-1);
        new_head->next = head;
        ListNode* p1=new_head,*p2=head,*p3=p2->next;
        p2->next = NULL;
        p2 = p2->next;
        while(p3)
        {
            ListNode* p3_next = p3->next;
            ListNode* p = p1->next,*pre_p=p1;
            while(p&&p3->val>p->val)
            {
                pre_p = p;
                p = p->next;
            }
            ListNode* tmp = pre_p->next;
            pre_p->next = p3;
            p3->next = tmp;
            p3 = p3_next;
        }
        return new_head->next;
    }
};
