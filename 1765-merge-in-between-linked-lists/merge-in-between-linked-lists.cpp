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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode * begin=list1;
        ListNode * end=list1;
        a--;
        while(begin!=NULL && begin->next!=NULL)
        {
            if(a==0)
            {
                break;
            }
            begin=begin->next;
            a--;
        }
        // b--;
        while(end!=NULL && end->next!=NULL)
        {
            if(b==0)
            {
                break;
            }
            end=end->next;
            b--;
        }
        begin->next=list2;
        while(list2!=NULL && list2->next!=NULL)
        {
            list2=list2->next;
        }
        list2->next=end->next;
        return list1;
    }
};