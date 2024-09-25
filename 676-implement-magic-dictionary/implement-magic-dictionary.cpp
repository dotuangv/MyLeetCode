class MagicDictionary {
public:
struct TreeNode{
    TreeNode *child[26];
    bool ok;
    TreeNode()
    {
        ok = false;
        for(int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
};
    TreeNode *root;
    MagicDictionary() {
        root = new TreeNode();
    }

    
    void buildDict(vector<string> dictionary) {
        for(int i = 0; i < dictionary.size(); i++){
            TreeNode *node = root;
            for(int j = 0; j < dictionary[i].size(); j++)
            {
                int k = dictionary[i][j] - 'a';
                if(!node->child[k]) node->child[k] = new TreeNode();
                node = node->child[k];
            }
            node->ok = true;
        }
    }
    
    bool search(string searchWord) {
        TreeNode *node = root;
        bool ans = false;
        for(int i = 0; i < searchWord.size(); i++)
        {
            int k = searchWord[i] - 'a';
            for(int j = 0; j < 26; j++)
            {
                TreeNode *node2 = node;
                if(j != k && node2->child[j])
                    ans |= Search2(searchWord, i + 1, node2->child[j]);
            }
            if(ans) return true;
            if(!node->child[k])
                return false;
            node = node->child[k];
        }
        return false;
    }
    bool Search2(string &searchWord, int j, TreeNode *node)
    {
        if(!node) return true;
        for(int i = j; i < searchWord.size(); i++)
        {
            int k = searchWord[i] - 'a';
            if(!node->child[k]) return false;
            node = node->child[k];
        }
        return node->ok;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */