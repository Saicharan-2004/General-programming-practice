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
        if(root==NULL)
        {
            ans = 0;
        }
        else
        {
            if(root->val >=currMaxi)
            {
                currMaxi=root->val;
                ans+=1;
            }
            ans+=helper(root->left,currMaxi)+helper(root->right,currMaxi);
        }
        return ans;
    }
    int goodNodes(TreeNode* root) 
    {
        return helper(root,-1e5);
    }
};