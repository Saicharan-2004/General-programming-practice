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
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root==NULL)
        {
            return root;
        }
        TreeNode *leftSide=invertTree(root->left);
        TreeNode *rightSide=invertTree(root->right);
        root->left=rightSide;
        root->right=leftSide;
        return root;
    }
};