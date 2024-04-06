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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root == NULL)
        {
            return {};
        }
        queue<TreeNode*>temp;
        temp.push(root);
        vector<vector<int>>ans;
        while(!temp.empty())
        {
            vector<int>rp;
            int n=temp.size();
            for(int i=0;i<n;i++)
            {
                TreeNode * curr=temp.front();
                temp.pop();
                if(curr != NULL)
                    rp.push_back(curr->val);
                if(curr != NULL && curr->left != NULL)
                    temp.push(curr->left);
                if(curr != NULL && curr->right != NULL)
                    temp.push(curr->right);
            }
            ans.push_back(rp);
        }
        return ans;
    }
};