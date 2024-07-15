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
    ListNode*reverse(ListNode * node)
    {
        if(node == NULL || node->next == NULL)  return node;
        ListNode*newNode = reverse(node->next);
        node->next->next = node;
        node->next = NULL;
        return newNode;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == NULL)
        {
            return head;
        }
        ListNode* temp = head;
        int n = 0;
        while(temp!=NULL)
        {
            n++;
            temp = temp->next;
        }
        k=k%n;
        if(k == 0)  return head;
        temp = head;
        while(temp!=nullptr && k > 0)
        {
            k--;
            temp = temp->next;
        }   
        ListNode* slow = head;
        ListNode * fast = temp;
        while(fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode * doosraHalf = slow->next;
        slow->next = NULL;
        ListNode * newHead = reverse(head);
        doosraHalf = reverse(doosraHalf);
        head->next = doosraHalf;
        return reverse(newHead);
    }
};