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
    int minimumOperations(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int cnt = 0, ans = 0;
        while(!q.empty()){
            vector<pair<int, int>> vt;
            int j = 0;
            while(!q.empty() && q.front().second == cnt){
                TreeNode *t = q.front().first;
                vt.push_back({t->val, j++});
                if(t->left != nullptr) q.push({t->left, cnt + 1});
                if(t->right != nullptr) q.push({t->right, cnt + 1});
                q.pop();
            }
            sort(vt.begin(), vt.end());
            int i = 0, res = 0;
            while(i < vt.size()){
                while(i != vt[i].second){
                    res++;
                    swap(vt[i], vt[vt[i].second]);
                }
                i++;
            }
            ans += res;
            cnt++;
        }
        return ans;
    }
};