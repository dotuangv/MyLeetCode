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
    void Solve(TreeNode *root, int depthcur, int depth, int val)
    {
        if(root != NULL)
        {
            if(depth == depthcur + 1)
            {
                TreeNode *ltree = new TreeNode(val, root->left, NULL);
                TreeNode *rtree = new TreeNode(val, NULL, root->right);
                root->left = ltree;
                root->right = rtree;
            }else
            {
                Solve(root->left, depthcur + 1, depth, val);
                Solve(root->right, depthcur + 1, depth, val);
            }
        }
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode *ans = new TreeNode(val, root, NULL);
            return ans;
        }
        Solve(root, 1, depth, val);
        return root;
    }
};