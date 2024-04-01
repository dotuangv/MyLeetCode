class Trie {
public:
    int trie[40005][26];
    bool ok[40005];
    int cnt = 0;
    Trie() {
        for(int i = 0; i <= 40000; i++)
        {
            for(int j = 0; j < 26; j++) trie[i][j] = 0;
        }
    }
    
    void insert(string word) {
        int u = 0;
        for(int i = 0; i < word.size(); i++)
        {
            int k = word[i] - 'a';
            if(!trie[u][k]) trie[u][k] = ++cnt;
            u = trie[u][k];
        }
        ok[u] = true;
    }
    
    bool search(string word) {
        int u = 0;
        for(int i = 0; i < word.size(); i++)
        {
            int k = word[i] - 'a';
            if(!trie[u][k]) return false;
            u = trie[u][k];
        }
        return ok[u];
    }
    
    bool startsWith(string prefix) {
        int u = 0;
        for(int i = 0; i < prefix.size(); i++)
        {
            int k = prefix[i] - 'a';
            if(!trie[u][k]) return false;
            u = trie[u][k];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */