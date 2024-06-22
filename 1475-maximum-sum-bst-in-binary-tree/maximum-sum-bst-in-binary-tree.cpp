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
 class helper{
    public:
    int sum;
    int mini;
    int maxi;
    helper(int sum,int mini,int maxi)
    {
        this->sum = sum;
        this->mini = mini;
        this->maxi = maxi;
    }
 };
class Solution {
public:
    int summer = INT_MIN;
    helper inorder(TreeNode * root)
    {
        if(root == NULL)
        {
            return helper(0,INT_MAX,INT_MIN);
        }
        helper leftT = inorder(root->left);
        helper rightT = inorder(root->right);
        if(leftT.maxi < root->val && root->val < rightT.mini)
        {
            summer = max(summer,leftT.sum + rightT.sum + root->val);
            return helper(leftT.sum + rightT.sum + root->val,min(leftT.mini,root->val),max(rightT.maxi,root->val));
        }
        // summer = max(summer,max(leftT.sum,rightT.sum));
        return helper(max(leftT.sum,rightT.sum),INT_MIN,INT_MAX);
    }
    int maxSumBST(TreeNode* root) {
        auto ans = inorder(root);
        return max(0,summer);
    }
};