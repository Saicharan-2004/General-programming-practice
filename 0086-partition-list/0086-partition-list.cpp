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
    ListNode* partition(ListNode* head, int x) 
    {
        vector<int>sec;
        vector<int>fir;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                fir.push_back(temp->val);
            }
            else
            {
                sec.push_back(temp->val);
            }
            temp=temp->next;
        }
        ListNode*ans=new ListNode(0);
        temp=ans;
        for(auto it:fir)
        {
            ans->next=new ListNode(it);
            ans=ans->next;
        }
        for(auto it:sec)
        {
            ans->next=new ListNode(it);
            ans=ans->next;
        }
        return temp->next;
    }
};