/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        while(root!=NULL)
        {
            int maxi=max(p->val,q->val);
            int mini=min(p->val,q->val);
            if(root->val < mini)
            {
                root=root->right;
            }
            else if(root->val > maxi)
            {
                root=root->left;
            }
            else
            {
                return root;
            }  
        }
        return NULL;
    }
};