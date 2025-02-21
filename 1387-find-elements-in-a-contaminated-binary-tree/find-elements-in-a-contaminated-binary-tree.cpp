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
class FindElements {
public:
    unordered_map<int, bool> mp;
    FindElements(TreeNode* root) {
        root->val = 0;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *t = st.top(); st.pop();
            mp[t->val] = true;
            if(t->left != NULL){
                t->left->val = t->val * 2 + 1;
                st.push(t->left);
            }
            
            if(t->right != NULL){
                t->right->val = t->val * 2 + 2;
                st.push(t->right);
            }
        }
    }
    
    bool find(int target) {
        return mp[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */