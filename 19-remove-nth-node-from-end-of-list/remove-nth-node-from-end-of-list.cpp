/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode*temp=head;
        int len=0;
        while(temp!=NULL)
        {
            len++;
            temp=temp->next;
        }
        int n_front=len-n-1;
        if(len==n)
        {
            return head->next;
        }
        if(n_front<0)
        {
            return NULL;
        }
        temp=head;
        while(n_front--)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};