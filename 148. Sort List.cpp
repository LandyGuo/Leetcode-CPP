/*
148. Sort List   
Difficulty: Medium
Sort a linked list in O(n log n) time using constant space complexity.
*/
/*2nd pass
思路：不断二分，每次二分返回链表第二段的首节点，然后对两个链表进行排序

*/
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		if (head==NULL||head->next==NULL)
			return head;
		ListNode* p1 = head, *p2 = split(head);
		ListNode* l1 = sortList(p1);
		ListNode* l2 = sortList(p2);
		return merge(l1, l2);

	}

	ListNode * merge(ListNode*l1, ListNode*l2)
	{
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		ListNode* new_head = new ListNode(-1);
		ListNode*p1 = l1, *p2 = l2, *p = new_head;
		while (p1&&p2)
		{
			if (p1->val <= p2->val)
			{
				ListNode* p1_nxt = p1->next;
				p1->next = NULL;
				p->next = p1;
				p1 = p1_nxt;
				p = p->next;
			}
			else if (p1->val>p2->val)
			{
				ListNode* p2_nxt = p2->next;
				p2->next = NULL;
				p->next = p2;
				p2 = p2_nxt;
				p = p->next;
			}
		}
		if (p1)
			p->next = p1;
		else if (p2)
			p->next = p2;
		return new_head->next;
	}


	ListNode* split(ListNode* head)
	{
		ListNode* p1 = head, *p2 = p1, *pre_p1 = NULL;
		while (p2)
		{
			pre_p1 = p1;
			p1 = p1->next;
			if (p1)
				p2 = p2->next ? p2->next->next : NULL;
		}
		pre_p1->next = NULL;
		return p1;
	}
};
