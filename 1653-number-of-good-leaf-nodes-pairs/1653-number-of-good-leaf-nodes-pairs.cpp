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
    vector<TreeNode*>leaf;
    void findParent(unordered_map<TreeNode*,TreeNode*>&tp,TreeNode*root)
    {
        if(root == NULL)    return ;
        if(root->left)
        {
            tp[root->left] = root;
        }
        if(root->right)
        {
            tp[root->right] = root;
        }
        if(root->left == NULL && root->right == NULL)   leaf.push_back(root);
        findParent(tp,root->left);
        findParent(tp,root->right);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,TreeNode*>tp;
        findParent(tp,root);
        int ans = 0;
        for(auto it:leaf)
        {
            int dis = 0;
            queue<TreeNode*>q;
            unordered_map<TreeNode*,int>visited;
            q.push(it);
            while(!q.empty())
            {
                int size = q.size();
                while(size--)
                {
                    auto front = q.front();
                    visited[front]++;
                    q.pop();
                    if(front->left && visited[front->left] == 0)
                    {
                        q.push(front->left);
                    }
                    if(front->right && visited[front->right] == 0)
                    {
                        q.push(front->right);
                    }
                    if(tp.find(front)!=tp.end() && visited[tp[front]] == 0)
                    {
                        q.push(tp[front]);
                    }
                    if(front->left == NULL && front->right == NULL)
                    {
                        if(dis<=distance)
                        {
                            ans++;
                        }
                    }
                }
                dis++;
                if(dis>distance)
                {
                    break;
                }
            }
        }
        return (ans-leaf.size())>>1;
    }
};