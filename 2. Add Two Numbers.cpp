/*
2. Add Two Numbers   
Difficulty: Medium
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*2nd pass:
 注意：在将指针往后移动之前，必须得先保证指针当前指向不为NULL
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * new_head = new ListNode(-1);
        ListNode* p=new_head,*p1=l1,*p2=l2;
        int carry_on = 0;
        while(p1||p2||carry_on)
        {
            int add1 = ((p1==NULL)?0:p1->val);
            int add2 = ((p2==NULL)?0:p2->val);
            int curNum = add1+add2+carry_on;
            int curVal = curNum%10;
            carry_on = curNum/10;

                p->next = new ListNode(curVal);
                p = p->next;
                if(p1!=NULL)//注意这里：只有当指针非空时才能再往后移动
                    p1 = p1->next;
                if(p2!=NULL)
                    p2 = p2->next;
        }
        return new_head->next;
    }
};
