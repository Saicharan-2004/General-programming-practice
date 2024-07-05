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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*prev=NULL;
        ListNode*curr=head;
        vector<int>check;
        int count = 0;
        while(curr!=NULL)
        {
            if(curr->next!=NULL && prev !=NULL)
            {
                if(prev->val > curr->val && curr->val < curr->next->val || (prev->val < curr->val && curr->val > curr->next->val))
                {
                    check.push_back(count);
                }
            }
            prev = curr;
            curr = curr->next;
            count++;
        }
        int n = check.size();
        if(n<=1)
        {
            return {-1,-1};
        }
        else
        {
            int mini = INT_MAX;
            for(int i = 0;i<n-1;i++)
            {
                mini= min(mini,abs(check[i]-check[i+1]));
            }
            int maxi = check[n-1]-check[0];
            return {mini,maxi};
        }
    }
};