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

    void Solve(TreeNode *root, int &x)
    {
        if(root != NULL)
        {
            Solve(root->right, x);
            root->val += x;
            x = root->val;
            Solve(root->left, x);
        }
    }

    TreeNode* bstToGst(TreeNode* root) {
        int x = 0;
        Solve(root, x);
        return root;
    }
};