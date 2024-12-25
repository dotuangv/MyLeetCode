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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        int heigh = 0, Max = root->val;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(heigh == y) Max = max(Max, x->val);
            else {
                ans.push_back(Max);
                Max = x->val;
                heigh = y;
            }
            if(x->left) q.push({x->left, y + 1});
            if(x->right) q.push({x->right, y + 1});
        }
        ans.push_back(Max);
        return ans;
    }
};