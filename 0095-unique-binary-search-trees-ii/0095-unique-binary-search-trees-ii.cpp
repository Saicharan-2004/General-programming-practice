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
    vector<TreeNode*>helper(int left,int right)
    {
        if(left>right)
        {
            return {NULL};
        }
        vector<TreeNode*>ans;
        for(int val=left;val<=right;val++)
        {
            vector<TreeNode*>leftSide=helper(left,val-1);
            vector<TreeNode*>rightSide=helper(val+1,right);
            for(auto it:leftSide)
            {
                for(auto t:rightSide)
                {
                    TreeNode* root=new TreeNode(val,it,t);
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) 
    {
        return helper(1,n);
    }
};