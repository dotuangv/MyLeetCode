class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size() == 0)
        {
            for(int i = 0; i < p.size(); i++) if(p[i] != '*') return false;
            return true;
        }
        vector<vector<bool>> dp(p.size() + 1, vector<bool> (s.size() + 1));
        dp[0][0] = true;
        int cnt = 0;
        for(int i = 1; i <= p.size(); i++)
        {
            bool ok = false;
            for(int j = 1; j <= s.size(); j++)
            {
                if(p[i - 1] == '*')
                {
                    dp[i][j] = max({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
                    if(cnt == 0) dp[i][0] = true;
                }
                else if(p[i - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                    cnt++;
                }
                else if(p[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                    cnt++;
                }
                if(dp[i][j]) ok = true;
            }
            if(!ok) return false;
        }
        return dp[p.size()][s.size()];
    }
};