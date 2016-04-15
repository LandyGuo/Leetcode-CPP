/*
23. Merge k Sorted Lists
Difficulty: Hard
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
/*2nd pass
思路：二分法，递归将原来一个列表拆分成两个子列表，然后自底向上合并
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty())
			return NULL;
		if (lists.size() == 1)
			return lists[0];
		if (lists.size() == 2)
			return merge(lists[0], lists[1]);
		vector<ListNode*>part1(lists.begin(), lists.begin() + lists.size() / 2);
		vector<ListNode*>part2(lists.begin() + lists.size() / 2, lists.end());
		ListNode* l1 = mergeKLists(part1);
		ListNode* l2 = mergeKLists(part2);
		return merge(l1, l2);
	}

	ListNode* merge(ListNode* l1, ListNode*l2)//merge 2 sorted lists
	{
		ListNode* new_head = new ListNode(-1);
		ListNode*p1 = l1, *p2 = l2, *p = new_head;
		while (p1&&p2)
		{
			if (p1->val <= p2->val)
			{
				ListNode* p1_next = p1->next;
				p1->next = NULL;
				p->next = p1;
				p1 = p1_next;
				p = p->next;

			}
			else if (p1->val>p2->val)
			{
				ListNode* p2_next = p2->next;
				p2->next = NULL;
				p->next = p2;
				p = p->next;
				p2 = p2_next;
			}
		}
		if (p1)
			p->next = p1;
		else if (p2)
			p->next = p2;
		return new_head->next;
	}


};
