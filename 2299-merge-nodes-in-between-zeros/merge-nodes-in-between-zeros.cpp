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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        ListNode*temp = head;
        while(temp!=NULL)
        {
            if(temp->val==0)
            {
                sum = 0;
            }
            else
            {
                temp->val = sum + temp->val;
                sum = temp->val;
            }
            temp = temp->next;
        }
        temp = head->next;
        ListNode *prev=NULL;
        ListNode * ans;
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->next->val == 0)
            {
                if(prev == NULL)
                {
                    ans = temp;
                    prev = temp;
                }
                else
                {
                    prev->next = temp;
                    prev=prev->next;
                }
            }
            temp=temp->next;
        }
        prev->next =NULL;
        return ans;
    }
};