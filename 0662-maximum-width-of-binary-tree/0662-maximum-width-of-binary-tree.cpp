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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>tp;
        tp.push({root,0});
        long long int ans = -1;
        while(!tp.empty())
        {
            long long int frontIndex = tp.front().second;
            long long int mini  = frontIndex;
            long long int backIndex = tp.back().second;
            ans = max(ans,(backIndex - frontIndex + 1));
            long long int n = tp.size();
            for(int i = 0;i<n;i++)
            {
                TreeNode * front = tp.front().first;
                frontIndex = tp.front().second - mini;
                tp.pop();
                if(front->left)
                {
                    tp.push({front->left,2*frontIndex + 1});
                }
                if(front->right)
                    tp.push({front->right,2*frontIndex + 2});
            }
        }
        return ans;
    }
};