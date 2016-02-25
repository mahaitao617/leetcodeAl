/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 
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
    ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;
    ListNode* pre=new ListNode(-1);
    ListNode* newhead=pre;
    pre->next=head;
    ListNode* cur=head;
    ListNode* Next=head->next;
    int tmpval=cur->val;
    while(Next)
    {
        if(tmpval!=Next->val)
        {
            tmpval=Next->val;
            Next=Next->next;
            pre=pre->next;
        }
        else
        {
        while(Next && tmpval==Next->val)
        {
          Next=Next->next;
        }
        if(!Next)
        {
            pre->next=NULL;
            return newhead->next;
        }
        pre->next=Next;
        tmpval=Next->val;
        Next=Next->next;
        }
    }
    return newhead->next;
    }
};
