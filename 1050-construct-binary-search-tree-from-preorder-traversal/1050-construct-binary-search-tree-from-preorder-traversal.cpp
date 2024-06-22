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
    TreeNode* helper(vector<int>preorder,int &ind,int up)
    {
        if(ind>=preorder.size() || preorder[ind] > up)
        {
            return NULL;
        }
        TreeNode * root  = new TreeNode(preorder[ind]);
        ind++;
        root->left = helper(preorder,ind,root->val);
        root->right = helper(preorder,ind,up);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return helper(preorder,ind,INT_MAX);
    }
};