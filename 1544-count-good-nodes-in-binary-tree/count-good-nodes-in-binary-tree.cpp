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
class Solution 
{
public:
    int helper(TreeNode * root,int currMaxi)
    {
        int ans=0;
        if(root != NULL && root->val >=currMaxi)
        {
            currMaxi = root->val;
            ans += 1;
        }
        if(root->left)
            ans += helper(root->left,currMaxi);
        if(root->right)
            ans += helper(root->right,currMaxi);
        return ans;
    }
    int goodNodes(TreeNode* root) 
    {
        return helper(root,-1e5);
    }
};