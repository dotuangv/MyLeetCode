class Solution {
public:
    int trie[3000][26];
    bool ok[3000];
    int cnt = 0;
    void insert(string &word) {
        int u = 0;
        for(int i = 0; i < word.size(); i++)
        {
            int k = word[i] - 'a';
            if(!trie[u][k]) trie[u][k] = ++cnt;
            u = trie[u][k];
        }
        ok[u] = true;
    }

    void search(string &word, int j, vector<int> &dp, int t) {
        int u = 0;
        for(int i = j; i < word.size(); i++)
        {
            int k = word[i] - 'a';
            if(!trie[u][k]) return;
            u = trie[u][k];
            if(ok[u])
            {
                dp[t] = max(dp[t], i - j + 1 + dp[i + 1]);
            }
        }
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
        for(int i = 0; i < dictionary.size(); i++)
        {
            insert(dictionary[i]);
        }
        vector<int> dp(s.size() + 1);
        for(int i = s.size() - 1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                search(s, j, dp, i);
            }
        }
        return s.size() - dp[0];
    }
};