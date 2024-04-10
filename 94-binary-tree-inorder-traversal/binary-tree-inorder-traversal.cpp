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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root == NULL)
        {
            return {};
        }
        stack<pair<TreeNode *,int>>temp1;
        vector<int>ans;
        temp1.push({root,1});
        while(temp1.size() > 0)
        {
            pair<TreeNode *,int> front = temp1.top();
            temp1.pop();
            if(front.first != NULL)
            {
                if(front.second == 1)
                {
                    front.second = 2;
                    temp1.push(front);
                    if(front.first->left != NULL)
                        temp1.push({front.first->left,1});
                }
                else if(front.second == 2)
                {
                    front.second = 3;
                    ans.push_back(front.first->val);
                    temp1.push(front);
                    if(front.first->right != NULL)
                        temp1.push({front.first->right,1});
                }
            }
        }
        return ans;
    }
};