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
    int height(TreeNode * root,bool &val)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=height(root->left,val);
        int rh=height(root->right,val);
        if(abs(lh-rh)>1)
        {
            val=false;
        }
        return max(1+lh,1+rh);
    }
    bool isBalanced(TreeNode* root) 
    {
        bool ans=true;
        height(root,ans);
        return ans;
    }
};