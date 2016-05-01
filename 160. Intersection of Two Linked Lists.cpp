/*
160. Intersection of Two Linked Lists  
Difficulty: Easy
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
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
 思路：2个链表一定是在最后公用一段：
先获取2个链表的长度，然后将长的链表头指针移动多出短的链表部分，然后开始一一对应的找
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1=0,length2=0;
        ListNode* p1 = headA,*p2 = headB;
        while(p1)
        {
            p1 = p1->next;
            length1++;
        }
        while(p2)
        {
            p2 = p2->next;
            length2++;
        }
        ListNode* longerList,*shorterList;
        if(length1>=length2) 
            longerList = headA,shorterList=headB;
        else longerList = headB,shorterList=headA;
        int diff = abs(length1-length2);
        ListNode* p = longerList,*q = shorterList;
        while(diff--)
            p =p->next;
        while(p!=q)
        {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
