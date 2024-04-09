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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root == NULL)
        {
            return {};
        }
        stack<TreeNode*>temp;
        temp.push(root);
        vector<int>ans;
        while(temp.size() > 0)
        {
            TreeNode * front = temp.top();
            ans.push_back(front->val);
            temp.pop();
            if(front->right)
            {
                temp.push(front->right);
            }
            if(front->left)
            {
                temp.push(front->left);
            }
        }
        return ans;
    }
};