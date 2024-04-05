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
        if(root==NULL || root==p || root == q)
        {
            return root;
        }
        TreeNode * leftT=lowestCommonAncestor(root->left,p,q);
        TreeNode * rightT=lowestCommonAncestor(root->right,p,q);
        if(leftT == NULL && rightT == NULL)
        {
            return NULL;
        }
        else if(leftT == NULL)
        {
            return rightT;
        }
        else if(rightT == NULL)
        {
            return leftT;
        }
        else
        {
            return root;
        }
    }
};