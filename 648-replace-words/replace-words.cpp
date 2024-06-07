class Solution {
public:
    int trie[100001][26];
    bool ok[100001];
    int cnt = 0;
    void insert(string &s)
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

    string query(string &s)
    {
        int u = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int k = s[i] - 'a';
            if(ok[u])
            {
                string res = "";
                for(int j = 0; j < i; j++) res += s[j];
                return res;
            }
            if(!trie[u][k])
            {
                return s;
            }
            u = trie[u][k];
        }
        return s;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for(int i = 0; i < dictionary.size(); i++)
        {
            insert(dictionary[i]);
        }
        string ans = "";
        int i = 0;
        while(i < sentence.size())
        {
            string res = "";
            while(i < sentence.size() && sentence[i] != ' ')
            {
                res += sentence[i];
                i++;
            }
            ans += query(res) + ' ';
            i++;
        }
        ans.pop_back();
        return ans;
    }
};