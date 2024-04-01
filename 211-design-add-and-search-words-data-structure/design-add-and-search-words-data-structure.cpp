class WordDictionary {
public:
    int trie[250005][26];
    bool ok[250005];
    int cnt = 0;
    WordDictionary() {
        for(int i = 0; i < 250000; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                trie[i][j] = 0;
            }
        }
    }
    
    void addWord(string word) {
        int u = 0;
        for(int i = 0; i < word.size(); i++)
        {
            int k = word[i] - 'a';
            if(!trie[u][k]) trie[u][k] = ++cnt;
            u = trie[u][k];
        }
        ok[u] = true;
    }
    
    void backtrack(int j, int u, string &word, bool &ans)
    {
        if(ans) return;
        if(j == word.size())
        {
            if(ok[u]) ans = true;
            return;
        }
        if(word[j] == '.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(trie[u][i]) backtrack(j + 1, trie[u][i], word, ans);
                if(ans) return;
            }
        }else
        {
            int k = word[j] - 'a';
            if(trie[u][k]) backtrack(j + 1, trie[u][k], word, ans);
        }
    }

    bool search(string word) {
        bool ans = false;
        backtrack(0, 0, word, ans);
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */