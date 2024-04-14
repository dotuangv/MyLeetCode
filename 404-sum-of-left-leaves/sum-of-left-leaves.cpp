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
    void sumleft(TreeNode* root, int left, int &sum)
    {
        if(root != NULL)
        {
            if(root->left == NULL && root->right == NULL)
            {
                if(left) sum += root->val;
            }else
            {
                sumleft(root->left, 1, sum);
                sumleft(root->right, 0, sum);
            }
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sumleft(root, 0, sum);
        return sum;
    }
};