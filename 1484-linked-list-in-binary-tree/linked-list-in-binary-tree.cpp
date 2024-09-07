/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
int seq[100], prv[100], N;

bool dfs(TreeNode *r, int p) {
    int v = r->val;
    while (p >= 0 && seq[p] != v) p = prv[p];
    ++p;
    if (p == N || r->left && dfs(r->left, p) || r->right && dfs(r->right, p)) return true;
    return false;
}

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        int n = 0;
        while (head) seq[n++] = head->val, head = head->next;
        prv[0] = -1;
        for (int i = 1; i < n; ++i) {
            int p = prv[i-1], lst = seq[i-1];
            while (p >= 0 && seq[p] != lst) p = prv[p];
            prv[i] = p+1;
        }
        N = n;
        return dfs(root, 0);
    }
};