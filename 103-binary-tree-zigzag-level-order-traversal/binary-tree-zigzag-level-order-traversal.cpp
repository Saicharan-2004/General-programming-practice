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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)    return {};
        stack<TreeNode*>s1,s2;
        s1.push(root);
        vector<vector<int>>ans;
        while(!s1.empty()||!s2.empty())
        {
            vector<int>curr;
            while(!s1.empty())
            {
                TreeNode* value = s1.top();
                curr.push_back(value->val);
                s1.pop();
                if(value->left)
                    s2.push(value->left);
                if(value->right)
                    s2.push(value->right);
            }
            ans.push_back(curr);
            curr.clear();
            while(!s2.empty())
            {
                TreeNode* value = s2.top();
                curr.push_back(value->val);
                s2.pop();
                if(value->right)
                    s1.push(value->right);
                if(value->left)
                    s1.push(value->left);
            }
            if(curr.size()>0)
                ans.push_back(curr);
        }
        return ans;
    }
};