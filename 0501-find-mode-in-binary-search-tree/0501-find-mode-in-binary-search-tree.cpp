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
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return ;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) 
    {
        vector<int>ans;
        inorder(root,ans);
        unordered_map<int,int>temp;
        for(auto it:ans)
        {
            temp[it]++;
        }
        int maxi=-1;
        for(auto it:temp)
        {
            maxi=max(maxi,it.second);
        }
        vector<int>finalans;
        for(auto it:temp)
        {
            if(it.second==maxi)
            {
                finalans.push_back(it.first);
            }
        }
        return finalans;
    }
};