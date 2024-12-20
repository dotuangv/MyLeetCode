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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto [x, y] = q.front();
            if(x == nullptr) break;
            if(y % 2 == 0){
                vector<TreeNode*> v, v2;
                while(!q.empty() && q.front().second == y){
                    auto [a, b] = q.front();
                    v.push_back(a);
                    q.push({a->left, b + 1});
                    q.push({a->right, b + 1});
                    q.pop();
                }
                for(int i = 0; i < v.size(); i++){
                    if(v[i]->left){
                        v2.push_back(v[i]->left);
                        v2.push_back(v[i]->right);
                    }
                }
                int l = 0, r = v2.size() - 1;
                while(l < r) swap(v2[l++]->val, v2[r--]->val);
            }else{
                q.push({x->left, y + 1});
                q.push({x->right, y + 1});
                q.pop();
            }
        }
        return root;
    }
};