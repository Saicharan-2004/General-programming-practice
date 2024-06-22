/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(unordered_map<TreeNode *,TreeNode *> &tp,TreeNode *root)
    {
        if(root == NULL)    return ;
        if(root->left)  tp[root->left] = root;
        if(root->right) tp[root->right] = root;
        helper(tp,root->left);
        helper(tp,root->right);
        return ;
    }
    vector<int>ans;
    void temp(unordered_map<TreeNode *,int> &visited,TreeNode * root,unordered_map<TreeNode *,TreeNode *> &tp,int ind,int k)
    {
        if(ind == k)
        {
            ans.push_back(root->val);
            return ;
        }
        if(root->left && visited.find(root->left) == visited.end())
        {
            visited[root->left]++;
            temp(visited,root->left,tp,ind+1,k);
        }
        if(root->right && visited.find(root->right) == visited.end())
        {
            visited[root->right]++;
            temp(visited,root->right,tp,ind+1,k);
        }
        if(tp.find(root)!=tp.end() && visited.find(tp[root]) == visited.end())
        {
            visited[tp[root]]++;
            temp(visited,tp[root],tp,ind+1,k);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode *> tp;
        unordered_map<TreeNode *,int> visited;
        visited[target]++;
        helper(tp,root);
        temp(visited,target,tp,0,k);
        return ans;
    }
};