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
    TreeNode* bstToGst(TreeNode* root) {
            int acc_sum = 0;
            sum_node(root,acc_sum);
            return root;
        }
        
    void sum_node(TreeNode* node, int& acc_sum){
        if (node == NULL)  return;
        sum_node(node->right,acc_sum);
        node->val += acc_sum;
        acc_sum = node->val;
        sum_node(node->left, acc_sum);
    }
    // TreeNode* bstToGst(TreeNode* root) {
    //     TreeNode * curr = root;
    //     vector<TreeNode*>inorder;
    //     while(curr != NULL)
    //     {
    //         if(curr->left == NULL)
    //         {
    //             inorder.push_back(curr);
    //             curr = curr->right;
    //         }
    //         else
    //         {
    //             TreeNode * prev = curr->left;
    //             while(prev->right!= NULL && prev->right!=curr)
    //             {
    //                 prev = prev->right;
    //             }
    //             if(prev ->right == NULL)
    //             {
    //                 prev->right = curr;
    //                 curr = curr->left;
    //             }
    //             else
    //             {
    //                 prev->right = NULL;
    //                 inorder.push_back(curr);
    //                 curr = curr->right;
    //             }
    //         }
    //     }
    //     int prefix = inorder.back()->val;
    //     for(int i = inorder.size()-2;i>=0;i--)
    //     {
    //         inorder[i]->val = inorder[i]->val + prefix;
    //         prefix = inorder[i]->val;
    //     }
    //     return root;
    // }
};