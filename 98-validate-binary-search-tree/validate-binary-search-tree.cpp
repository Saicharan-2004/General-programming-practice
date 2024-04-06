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
    bool helper(TreeNode * root,long long int mini,long long int maxi)
    {
        bool ans= true;
        if(root == NULL)
        {
            return ans;
        }
        if(root->val <= mini || root->val >= maxi)
        {
            return false;
        }
        return helper(root->left,mini,root->val) && helper(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) 
    {
        if(root->left ==NULL && root->right == NULL)
            return true;
        long long int mini = -1000000000000, maxi = 1000000000000;
        return helper(root,mini,maxi);
    }
};