class Solution {
public:
    vector<string> TachXau(string &s)
    {
        vector<string> ans;
        string str = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                ans.push_back(str);
                str.clear();
            }else str.push_back(s[i]);
        }
        ans.push_back(str);
        return ans;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        map<string, int> mp1, mp2;
        vector<string> s = TachXau(s1);
        for(auto x: s) mp1[x]++;
        s = TachXau(s2);
        for(auto x: s) mp2[x]++;
        for(auto x: mp1) if(mp1[x.first] == 1 && mp2[x.first] == 0) ans.push_back(x.first);
        for(auto x: mp2) if(mp2[x.first] == 1 && mp1[x.first] == 0) ans.push_back(x.first);
        return ans;
    }
};