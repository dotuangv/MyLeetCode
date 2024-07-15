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
    TreeNode* solve(int x, unordered_map<int, pair<int, int>> &mp)
    {
        TreeNode *t = new TreeNode(x);
        if(mp[x].first == 0 && mp[x].second == 0) return t;
        else
        {
            if(mp[x].first != 0)
            {
                t->left = solve(mp[x].first, mp);
            }
            if(mp[x].second != 0)
            {
                t->right = solve(mp[x].second, mp);
            }
            return t;
        }
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<int, int>> mp;
        unordered_map<int, bool> mp2;
        for(auto &x: descriptions)
        {
            if(x[2]) mp[x[0]].first = x[1];
            else mp[x[0]].second = x[1];
            mp2[x[1]] = true;
        }
        int head;
        for(auto &x: mp)
        {
            if(!mp2[x.first])
            {
                head = x.first;
                break;
            }
        }
        return solve(head, mp);
    }
};