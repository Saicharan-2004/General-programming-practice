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
    int countNodes(TreeNode* root) {
        if(root==NULL)  return 0;
        TreeNode * curr = root;
        int leftC=0,rightC=0;
        while(curr!=NULL)
        {
            leftC++;
            curr=curr->left;
        }
        curr = root;
        while(curr!=NULL)
        {
            rightC++;
            curr = curr->right;
        }
        if(leftC == rightC)
        {
            return pow(2,leftC) - 1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};