 Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

//Method 1

class Solution {

public:

    ListNode* swapPairs(ListNode* head) {

    if(head==NULL || head->next==NULL)return head;

    ListNode *cur=head;

    ListNode *preNode=NULL;

    ListNode *temp=NULL;

    while(cur!=NULL && cur->next!=NULL)

    {

        temp=cur->next;

        cur->next=temp->next;

        temp->next=cur;

        if(preNode)

        preNode->next=temp;

        else

        head=temp;

        preNode=cur;

        cur=cur->next;

    }

    return head;

    }

};



//方法二

ListNode* swapPairs(ListNode* head) {
    ListNode **pp = &head, *a, *b;
    while ((a = *pp) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *pp = b;
        pp = &(a->next);
    }
    return head;
