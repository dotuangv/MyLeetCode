class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<bool> check(s.size(), false);
        map<char, vector<int>> m1, m2;
        for(int i = 0; i < s.size(); i++)
        {
            m1[s[i]].push_back(i);
            m2[t[i]].push_back(i);
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(!check[i])
            {
                if(m1[s[i]].size() != m2[t[i]].size()) return false;
                else
                {
                    for(int j = 0; j < m1[s[i]].size(); j++)
                    {
                        if(m1[s[i]][j] != m2[t[i]][j]) return false;
                        check[m1[s[i]][j]] = true;
                    }
                }
                check[i] = true;
            }
        }
        return true;
    }
};