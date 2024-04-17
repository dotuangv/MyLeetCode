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
    string solve(TreeNode *root)
    {
        if(root != NULL)
        {
            if(root->left != NULL && root->right != NULL)
            {
                char c = char(root->val + 'a');
                string s1 = solve(root->left) + c;
                string s2 = solve(root->right) + c;
                for(int i = 0; i < min(s1.size(), s2.size()); i++)
                {
                    if(s1[i] > s2[i]) return s2;
                    else if(s1[i] < s2[i]) return s1;
                }
                if(s1.size() < s2.size())
                {
                    for(int j = s1.size(); j < s2.size(); j++)
                    {
                        if(s2[j] > c) return s1;
                    }
                    if(s2.size() - 1 > s1.size()) return s2;
                    return s1;
                }
                else
                {
                    for(int j = s2.size(); j < s1.size(); j++)
                    {
                        if(s1[j] > c) return s2;
                    }
                    if(s1.size() - 1 > s2.size()) return s1;
                    return s2;
                }
            }else if(root->left != NULL)
            {
                return solve(root->left) + char(root->val + 'a');
            }else if(root->right != NULL)
            {
                return solve(root->right) + char(root->val + 'a');
            }else
            {
                string s = "";
                s += char(root->val + 'a');
                return s;
            }
        }else return "";
    }
    string smallestFromLeaf(TreeNode* root) {
        return solve(root);
    }
};