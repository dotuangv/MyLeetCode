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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<unsigned long long, TreeNode*>> q;
        q.push({0, root});
        unsigned long long ans = 1;
        while(!q.empty()){
            int t = q.size();
            unsigned long long l = -1;
            while(t--){
                auto &[x, y] = q.front();
                if(y->left){
                    if(l == -1) l = 2 * x;
                    ans = max(ans, 2 * x - l + 1);
                    q.push({2 * x, y->left});
                }
                if(y->right){
                    if(l == -1) l = 2 * x + 1;
                    ans = max(ans, 2 * x + 1 - l + 1);
                    q.push({2 * x + 1, y->right});
                }
                q.pop();
            }
        }
        return ans;
    }
};