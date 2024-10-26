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


    struct Node{
        TreeNode *node;
        int height;
        bool left;
        Node(TreeNode *node, int height, bool left) : node(node), height(height), left(left){}
    };

    vector<int> dp, ans;

    int dfs(TreeNode *root)
    {
        if(root == NULL) return -1;
        return dp[root->val] = 1 + max(dfs(root->left), dfs(root->right));
    }


    void bfs(TreeNode *root)
    {
        dfs(root);
        queue<Node> q;
        int l = 0, r = 0;
        bool start = true;
        q.push(Node(root, 0, true));
        if(root->left != NULL) l = 1 + dp[root->left->val];
        if(root->right != NULL) r = 1 + dp[root->right->val];
        while(!q.empty())
        {
            TreeNode *node = q.front().node;
            int height = q.front().height;
            bool left = q.front().left;
            q.pop();
            if(start)
            {
                start = false;
                if(l) {
                    ans[node->left->val] = r;
                    q.push(Node(node->left, height + 1, true));
                }
                if(r) {
                    ans[node->right->val] = l;
                    q.push(Node(node->right, height + 1, false));
                }
            }else
            {
                if(left)
                {
                    if(node->left != NULL)
                    {
                        if(node->right != NULL)
                            ans[node->left->val] = max({r, height + 1 + dp[node->right->val], ans[node->val]});
                        else
                            ans[node->left->val] = max({r, height, ans[node->val]});
                        q.push(Node(node->left, height + 1, left));
                    }
                    if(node->right != NULL)
                    {
                        if(node->left != NULL)
                            ans[node->right->val] = max({r, height + 1 + dp[node->left->val], ans[node->val]});
                        else
                            ans[node->right->val] = max({r, height, ans[node->val]});
                        q.push(Node(node->right, height + 1, left));
                    }
                }else
                {
                    if(node->left != NULL)
                    {
                        if(node->right != NULL)
                            ans[node->left->val] = max({l, height + 1 + dp[node->right->val], ans[node->val]});
                        else
                            ans[node->left->val] = max({l, height, ans[node->val]});
                        q.push(Node(node->left, height + 1, left));
                    }
                    if(node->right != NULL)
                    {
                        if(node->left != NULL)
                            ans[node->right->val] = max({l, height + 1 + dp[node->left->val], ans[node->val]});
                        else
                            ans[node->right->val] = max({l, height, ans[node->val]});
                        q.push(Node(node->right, height + 1, left));
                    }
                }
            }
        }
    }


    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        dp.resize(100001);
        ans.resize(100001, 0);
        bfs(root);
        vector<int> result(queries.size());
        for(int i = 0; i < queries.size(); i++) result[i] = ans[queries[i]];
        return result;
    }
};