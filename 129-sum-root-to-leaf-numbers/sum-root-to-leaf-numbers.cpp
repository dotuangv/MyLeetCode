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
    int sum = 0;
    void solve(TreeNode *root, string &s)
    {
        if(root != NULL)
        {
            s += char(root->val + 48);
            if(root->left == NULL && root->right == NULL)
            {
                long long res = 0, t = 1;
                for(int i = s.size() - 1; i >= 0; i--)
                {
                    res += (s[i] - 48)*t;
                    t*=10;
                }
                sum += res;
            }else if(root->right == NULL)
            {
                solve(root->left, s);
                s.pop_back();
            }else if(root->left == NULL)
            {
                solve(root->right, s);
                s.pop_back();
            }else
            {
                solve(root->left, s);
                s.pop_back();
                solve(root->right, s);
                s.pop_back();
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        string s = "";
        solve(root, s);
        return sum;
    }
};