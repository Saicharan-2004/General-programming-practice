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
    vector<TreeNode*>ans;
    void helper(TreeNode* &root,unordered_set<int>del)
    {
        if(root == NULL)
        {
            return ;
        }
        helper(root->left,del);
        helper(root->right,del);
        if(del.find(root->val) != del.end())
        {
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            root = NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>deleteNodes;
        for(auto it:to_delete)
        {
            deleteNodes.insert(it);
        }
        helper(root,deleteNodes);
        if(root!=NULL)
            ans.push_back(root);
        return ans;
    }
};