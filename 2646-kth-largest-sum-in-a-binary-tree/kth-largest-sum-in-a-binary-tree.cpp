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
    vector<long long> ans;

    long long kthLargestLevelSum(TreeNode* root, int k) {
        stack<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            pair<TreeNode*, int> t = q.top();
            q.pop();
            if(ans.size() <= t.second) ans.push_back(t.first->val);
            else ans[t.second] += t.first->val;
            if(t.first->left != NULL) q.push({t.first->left, t.second + 1});
            if(t.first->right != NULL) q.push({t.first->right, t.second + 1});
        }
        if(k > ans.size()) return -1;
        sort(ans.begin(), ans.end(), greater<long long>());
        return ans[k - 1];
    }
};