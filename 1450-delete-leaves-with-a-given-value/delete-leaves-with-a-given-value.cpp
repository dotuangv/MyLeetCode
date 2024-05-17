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
    void dfs(TreeNode *root, int target, bool &check)
    {
        if(root != NULL)
        {
            if(root->left != NULL && root->right != NULL)
            {
                dfs(root->left, target, check);
                if(check)
                {
                    root->left = NULL;
                    check = false;
                }
                dfs(root->right, target, check);
                if(check)
                {
                    root->right = NULL;
                    check = false;
                }
                if(root->left == NULL && root->right == NULL && root->val == target) check = true;
            }
            else if(root->left != NULL)
            {
                dfs(root->left, target, check);
                if(check)
                {
                    root->left = NULL;
                    check = false;
                }
                if(root->left == NULL && root->right == NULL && root->val == target) check = true;
            }else if(root->right != NULL)
            {
                dfs(root->right, target, check);
                if(check)
                {
                    root->right = NULL;
                    check = false;
                }
                if(root->left == NULL && root->right == NULL && root->val == target) check = true;
            }else
            {
                if(root->val == target) check = true;
            }
        }
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool check = false;
        dfs(root, target, check);
        if(root->left == NULL && root->right == NULL && root->val == target) return NULL;
        return root;
    }
};