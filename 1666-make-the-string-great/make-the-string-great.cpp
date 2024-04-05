class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(ans.size() != 0)
            {
                if(ans.back() + 32 == s[i] || ans.back() == s[i] + 32)
                {
                    ans.pop_back();
                }else
                {
                    ans += s[i];
                }
            }else ans += s[i];
        }
        return ans;
    }
};