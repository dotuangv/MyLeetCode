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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int s = q.size();
            vector<long long> vt;
            vector<TreeNode*> v;
            root->val = 0;
            long long sum = 0;
            for(int i = 0; i < s; i++)
            {
                TreeNode *t = q.front();
                q.pop();
                long long S = 0, cnt = 0;
                if(t->left != NULL)
                {
                    S += t->left->val;
                    q.push(t->left);
                    v.push_back(t->left);
                    cnt ++;
                }
                if(t->right != NULL)
                {
                    S += t->right->val;
                    q.push(t->right);
                    v.push_back(t->right);
                    cnt++;
                }
                sum += S;
                for(int i = 0; i < cnt; i++) vt.push_back(S);
            }
            for(int i = 0; i < v.size(); i++)
            {
                v[i]->val = sum - vt[i];
            }
            
        }
        return root;
    }
};