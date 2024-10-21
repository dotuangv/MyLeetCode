class Solution {
public:

    int ans = 0;
    void backtrack(int i, string &s, map<string, int> &mp)
    {
        if(i == s.size())
        {
            int res = 0;
            for(auto x: mp) if(x.second != 0) res++;
            ans = max(ans, res);
            return; 
        }
        string str = "";
        for(int j = i; j < s.size(); j++)
        {
            str.push_back(s[j]);
            mp[str]++;
            backtrack(j + 1, s, mp);
            mp[str]--;
        }
    }

    int maxUniqueSplit(string s) {
        map<string, int> mp;
        backtrack(0, s, mp);
        return ans;
    }
};