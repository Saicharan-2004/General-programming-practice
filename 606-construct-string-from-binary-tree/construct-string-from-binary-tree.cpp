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
    string str="";
    void traversal(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        str += to_string(root->val);
        if (root->left || root->right) 
        {
            str += '(';
            traversal(root->left);
            str += ')';
        }
        if (root->right) 
        {
            str += '(';
            traversal(root->right);
            str += ')';
        }
    }
    string tree2str(TreeNode* root) 
    {
        traversal(root);
        return str;
    }
};