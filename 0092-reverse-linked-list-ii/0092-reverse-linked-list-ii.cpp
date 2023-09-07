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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if (!head || left == right) return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        ListNode* current = prev->next;
        
        for (int i = 0; i < right - left; ++i) {
            ListNode* next_node = current->next;
            current->next = next_node->next;
            next_node->next = prev->next;
            prev->next = next_node;
        }
        
        return dummy.next;
        // if(head==NULL || left==right)
        //     return head;
        // ListNode*prev=head;
        // for(int i=0;i<left-1;i++)
        // {
        //     prev=prev->next;
        // }
        // ListNode*current=prev->next;
        // for(int i=0;i<(right-left);i++)
        // {
        //     ListNode* next_node = current->next;
        //     current->next = next_node->next;
        //     next_node->next = prev->next;
        //     prev->next = next_node;
        // }
        // return head;
        // ListNode *prev1=NULL;
        // ListNode*curr=temp;
        // ListNode*nextptr=temp->next;
        // // if(leftN)
        // // {
        // //     nextptr=leftN->next;
        // // }
        // int i=right-left+1;
        // while(curr!=NULL && i--)
        // {
        //     curr->next=prev1;
        //     prev1=curr;
        //     curr=nextptr;
        //     nextptr=nextptr->next;
        // }
        // prev->next=prev1;
        // temp->next=curr;
        // return head;
    }
};