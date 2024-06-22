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
    int path(int &maxi,TreeNode* root){
        if(!root)
        return 0;
        int l=path(maxi,root->left);
        int r=path(maxi,root->right);
        maxi=max(maxi,max(0,l) + max(0,r)+root->val);
        return root->val+max(0,max(l,r));
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        path(maxi,root);
        return maxi;
    }
};