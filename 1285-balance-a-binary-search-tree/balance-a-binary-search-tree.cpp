/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode * balance(int start,int end,vector<int>inorder)
    {
        if(start>end)   return NULL;
        int mid = (start+end)/2;
        TreeNode * root = new TreeNode(inorder[mid]);
        root->left =  balance(start,mid-1,inorder);
        root->right =  balance(mid+1,end,inorder);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        TreeNode * curr = root;
        while(curr!= NULL)
        {
            if(curr->left == NULL)
            {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode * prev = curr->left;
                while(prev->right!=NULL && prev->right!=curr)
                {
                    prev = prev->right;
                }
                if(prev->right!=NULL)
                {
                    inorder.push_back(curr->val);
                    curr = curr->right;
                    prev->right = NULL;
                }
                else
                {
                    prev->right = curr;
                    curr = curr->left;
                }
            }
        }
        return balance(0,inorder.size()-1,inorder);
    }
};