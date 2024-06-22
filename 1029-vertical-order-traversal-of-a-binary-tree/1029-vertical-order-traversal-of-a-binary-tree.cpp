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
    map<int,map<int,priority_queue<int,vector<int>,greater<int>>>>tp;
    void helper(TreeNode * root,int y,int x)
    {
        if(root == NULL)
        {
            return ;
        }
        tp[y][x].push(root->val);
        helper(root->left,y-1,x+1);
        helper(root->right,y+1,x+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root,0,0);
        vector<vector<int>>ans;
        for(auto it:tp)
        {
            vector<int>temp;
            for(auto i:it.second)
            {
                while(!i.second.empty())
                {
                    temp.push_back(i.second.top());
                    i.second.pop();
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};