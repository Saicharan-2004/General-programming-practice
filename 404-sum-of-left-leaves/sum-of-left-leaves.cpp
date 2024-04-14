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
    void helper(TreeNode * root,int &sum,bool leftSide)
    {
        if(root == NULL)
        {
            return ;
        }
        if(root->left == NULL && root->right == NULL)
        {
            if(leftSide)
            {
                sum+=root->val;
            }
        }
        if(root->left)
        {
            helper(root->left,sum,1);
        }
        if(root->right)
        {
            helper(root->right,sum,0);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root,sum,0);
        return sum;
    }
};