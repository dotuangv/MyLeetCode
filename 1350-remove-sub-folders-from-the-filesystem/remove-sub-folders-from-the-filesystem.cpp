class Solution {
public:

    struct TreeNode{
        unordered_map<string, TreeNode*> child;
        bool ok;
        bool stop;
        TreeNode(){
            ok = false;
            stop = false;
        }
    };
    TreeNode *root;

    void build(string &s)
    {
        TreeNode *node = root;
        int i = 0;
        while(i < s.size())
        {
            string res = "";
            res.push_back(s[i++]);
            while(i < s.size() && s[i] != '/') res.push_back(s[i++]);
            if(!node->child[res]) node->child[res] = new TreeNode();
            node = node->child[res];
        }   
        node->ok = true;
    }

    string search(string &s)
    {
        TreeNode *node = root;
        string result = "";
        int i = 0;
        while(i < s.size())
        {
            string res = "";
            res.push_back(s[i++]);
            while(i < s.size() && s[i] != '/') res.push_back(s[i++]);
            node = node->child[res];
            result += res;
            if(node->stop) return "";
            if(node->ok) {
                node->stop = true;
                return result;
            }
        }
        return result;
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        root = new TreeNode();
        for(int i = 0; i < folder.size(); i++) build(folder[i]);
        vector<string> ans;
        for(int i = 0; i < folder.size(); i++)
        {
            string s = search(folder[i]);
            if(s != "") ans.push_back(s);
        }
        return ans;
    }
};