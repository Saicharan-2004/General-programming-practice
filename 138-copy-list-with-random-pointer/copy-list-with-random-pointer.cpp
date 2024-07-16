/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node*temp = head;
        while(temp!=NULL)
        {
            Node*newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp=temp->next->next;
        }
        Node*dum = new Node(-1);
        Node*res = dum;
        temp = head;
        while(temp!=NULL && temp->next!=NULL)
        {
            if(temp->random != NULL)
                temp->next->random = temp->random->next;
            else
                temp->next->random = nullptr;
            temp = temp->next->next;
        }
        temp = head;
        while(temp!=NULL)
        {
            dum->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            dum = dum->next;
        }
        return res->next;
    }
};