class Solution {
public:

    int ans = 0;
    void backtrack(int i, string &s, int res, map<string, int> &mp)
    {
        if(i == s.size())
        {
            ans = max(ans, res);
            return; 
        }
        string str = "";
        for(int j = i; j < s.size(); j++)
        {
            str.push_back(s[j]);
            mp[str]++;
            if(mp[str] == 1) backtrack(j + 1, s, res + 1, mp);
            else backtrack(j + 1, s, res, mp);
            mp[str]--;
        }
    }

    int maxUniqueSplit(string s) {
        map<string, int> mp;
        backtrack(0, s, 0, mp);
        return ans;
    }
};