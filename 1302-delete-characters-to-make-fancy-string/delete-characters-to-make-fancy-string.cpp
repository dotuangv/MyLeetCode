class Solution {
public:
    string makeFancyString(string s) {
        if(s.size() <= 2) return s;
        string ans = "";
        ans.push_back(s[0]);
        ans.push_back(s[1]);
        for(int j = 2; j < s.size(); j++)
        {
            if(s[j] != s[j - 1]) ans.push_back(s[j]);
            else if(s[j] != s[j - 2]) ans.push_back(s[j]);
        }
        return ans;
    }
};