class Solution {
public:
    int trie[10005][26];
    bool ok[10005];
    int cnt = 0;
    void Add(string &s)
    {
        int u = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int k = s[i] - 'a';
            if(!trie[u][k]) trie[u][k] = ++cnt;
            u = trie[u][k];
        }
        ok[u] = true;
    }

    bool Query(string &s)
    {
        int u = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int k = s[i] - 'a';
            if(!trie[u][k]) return false;
            u = trie[u][k];
        }
        return ok[u];
    }
    vector<string> ans;
    void backtrack(int i, string &s, string res)
    {
        if(i >= s.size()) return;
        string tmp = "";
        tmp += s[i];
        for(int j = i + 1; j < s.size(); j++)
        {
            if(Query(tmp))
            {
                backtrack(j, s, res + tmp + " ");
            }
            tmp += s[j];
        }
        if(Query(tmp)) ans.push_back(res + tmp);
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i = 0; i < wordDict.size(); i++)
        {
            Add(wordDict[i]);
        }
        backtrack(0, s, "");
        return ans;
    }
};